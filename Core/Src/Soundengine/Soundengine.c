/*
 * Soundengine.c
 *
 *  Created on: Mar 24, 2020
 *      Author: julian
 *
 * Copyright (C) 2012-2026 Erica Synths
 * SPDX-License-Identifier: GPL-3.0-only
 *
 * This file is part of the LXR firmware. It is licensed under the GNU General
 * Public License version 3, with the additional permission and terms in
 * NOTICE.md. See LICENSE and NOTICE.md in the root of the repository.
 */
#include "Soundengine/Soundengine.h"
#include "Soundengine/AudioCodecManager.h"
#include "Preset/PresetManager.h"
#include <string.h>
//#include "Soundengine/USB/usb_manager.h"
#include "Soundengine/MIDI/Uart.h"

//CPU meter (SHIFT + FX): CPU cycles of the slowest block since soundengine_getCpuPeak() was last called.
//Measured with the DWT cycle counter, which DWT_Delay_Init() starts at boot
static volatile uint32_t soundengine_peakCycles = 0;

uint8_t soundengine_getCpuPeak()
{
	const uint32_t cycles = soundengine_peakCycles;
	soundengine_peakCycles = 0;

	//time available for one block, in CPU cycles
	const float blockCycles = (float)SystemCoreClock * OUTPUT_DMA_SIZE / REAL_FS;
	const float percent = cycles * 100.f / blockCycles;
	return percent > 255.f ? 255 : (uint8_t)percent;
}

uint8_t soundengine_calcNextSampleBlock()
{
	if(bCurrentSampleValid!= SAMPLE_VALID)
	{
		const uint32_t start = DWT->CYCCNT;
	#if USE_DAC2
		mixer_calcNextSampleBlock((int16_t*)&dma_buffer[bCurrentSampleValid*(OUTPUT_DMA_SIZE*2)],(int16_t*)&dma_buffer2[bCurrentSampleValid*(OUTPUT_DMA_SIZE*2)]);
	#else
		mixer_calcNextSampleBlock(&dma_buffer[bCurrentSampleValid*(OUTPUT_DMA_SIZE*2)],&dma_buffer2[(1-bCurrentSampleValid)*(OUTPUT_DMA_SIZE*2)]);
	#endif
		const uint32_t cycles = DWT->CYCCNT - start;
		if(cycles > soundengine_peakCycles)
		{
			soundengine_peakCycles = cycles;
		}
		bCurrentSampleValid = SAMPLE_VALID;

		return 1;
	}

	return 0;
}

void soundengine_init()
{
	mixer_init();



	// start the audio codec
//#ifndef DEBUG
	CodecInit(SYNTH_FS);
//#endif

	parameterArray_init();

#if !EURORACK_MODULE
	euklid_init();
#endif


#if OLD_LFO_ROUTING
	int i;
	for(i=0;i<6;i++)
	{
		modNode_init(&velocityModulators[i]);
	}
#endif

	//init the seq speed
#if !EURORACK_MODULE
	seq_init();
	seq_setBpm(120);
#endif
	memset(midi_MidiChannels,0,8);
//	memset(midi_NoteOverride,0,7);

	initDrumVoice();
	Snare_init();
	HiHat_init();
	Cymbal_init();

	//precalc the first dma buffer block
	soundengine_calcNextSampleBlock();

	FPU->FPDSCR |= FPU_FPDSCR_FZ_Msk ; //enable flush to zero
}

void soundengine_process()
{
#if CALC_SAMPLES_IN_INTERRUPT
	__HAL_TIM_DISABLE_IT(&htim2, TIM_IT_UPDATE);
	//HAL_TIM_Base_Stop_IT(&htim2);
#if !EURORACK_MODULE
	seq_tick();
#endif
	soundengine_calcNextSampleBlock();
	//__HAL_TIM_SetCounter(&htim2, 450);
	//HAL_TIM_Base_Start_IT(&htim2);
	__HAL_TIM_ENABLE_IT(&htim2, TIM_IT_UPDATE);
#endif
	//generate next sample if no valid sample is present
#if !CALC_SAMPLES_IN_INTERRUPT
#if 1//#ifndef DEBUG
#if !EURORACK_MODULE
	seq_tick();
#endif
		soundengine_calcNextSampleBlock();



#endif
#endif
#if !EURORACK_MODULE
		//process midi on midi port
		uart_processMidi();
#endif
		//process the sequencer
	//	seq_tick(); //moved to tim 14?
#if !EURORACK_MODULE
	usb_tick();
#endif
	//process incoming frontpanel data
		//	uart_processFront();






	preset_morph_tick();
	//preset_morph_tick();
	//preset_morph_tick();

}
