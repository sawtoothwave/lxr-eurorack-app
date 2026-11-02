# Modifications

This is unofficial custom firmware for the Erica Synths LXR Eurorack module, based on the official
v1.51 source. It is not made, approved or supported by Erica Synths. See [NOTICE.md](NOTICE.md).

This file lists every change from the official firmware. Everything not listed here works as in the
official v1.51.

**Terms used below**
- **Select buttons 1–8**: the 8 buttons along the bottom, numbered left to right.
- **DRUM**: select button 1 while it is held down.
- **Sub pages**: the pages within a drum (OSC, AEG and so on) that select buttons 2–8 pick.
- **LFO page**: the page with a drum's LFO settings, opened with SHIFT + MOD.
- **Mod matrix**: the page opened by pressing MOD on its own.

## Versions

Custom versions are numbered as the official version they're based on plus a custom release number,
for example **1.51-c2**. The start-up screen and the update file name show the full version.

| Version | Changes |
|---|---|
| 1.51-c3 | Fixes from OpenElixir-02. Not released yet. |
| 1.51-c2 | FX routing shortcut, stereo delay echoes, restart shortcut, delay fix. |
| 1.51-c1 | Start-up screen, LFO shortcuts, muting in perform mode, fixes. This version still showed "1.51" on the start-up screen. |

## Start-up screen

The first line of the start-up screen reads **"Custom firmware"** instead of "Sonic Potions", as the
licence requires for modified firmware. The second line reads "LXR2 V" and the version, for example
"LXR2 V1.51-c2", instead of "LXR2 Drums V1.51", to make room for the custom version number.

## LFO shortcuts

There are 6 LFOs, one per drum. The closed and open hi-hats (drums 6 and 7) share LFO 6.

| Shortcut | What it does |
|---|---|
| Hold **MOD** + select button 2–8 | Opens the LFO page for drum 1–7. |
| Hold **DRUM** + select button 2–8, while the MOD light is on (mod matrix or LFO page) | Opens the LFO page for drum 1–7. |

With both shortcuts:
- **The active drum doesn't change.** Only the LFO on screen changes. Leaving the LFO page (EDIT, or a
  select button on its own) returns to the drum you were editing.
- **A message shows while you hold the button.** The screen shows "Selected LFO / LFO x" while MOD or
  DRUM is held. Press other select buttons to pick a different LFO, then release to see that LFO's
  settings.
- **Select buttons 7 and 8 both show LFO 6.**

Outside the mod matrix and LFO page, DRUM + select button switches drums as before.

## Muting in perform mode

Muting no longer needs a button combination. Select buttons 2–8 control drums 1–7.

| In perform mode | What it does |
|---|---|
| Select button 2–8 | Mutes or unmutes the drum. |
| Hold **SHIFT** + select button 2–8 | Plays the drum, as in EDIT mode. |
| Hold **DRUM** + select button 2–8 | Nothing. In the official firmware this muted the drum. |

- **The lights show what's playing.** When you enter perform mode, the select buttons of all unmuted
  drums light up. A muted drum's light is off.
- **An unmuted drum's light blinks off when the drum plays.** A muted drum doesn't play, so its light
  stays off.
- **In the official firmware, a select button on its own played the drum.** That moved to
  SHIFT + select button.

## FX routing shortcut

| Shortcut | What it does |
|---|---|
| Hold **FX** | Opens the FX page, as before. Select buttons 2–8 light up for the drums sent to the FX bus. |
| Hold **FX** + select button 2–8 | Sends drum 1–7 to the FX bus, or takes it off the FX bus. |

- **Taking a drum off the FX bus puts it back on its previous output.** The previous output is
  remembered until you switch the module off or load a kit. It isn't saved in the kit, so kits stay
  compatible with the official firmware.
- **If there's no previous output, the drum goes to the FX bus's output.** This happens when the kit
  loaded with the drum already on FX, or when you set it to FX in the menu.
- **Select buttons 7 and 8 both switch the hi-hats.** The closed and open hi-hats share an output.
- **Drum lights don't flash on hits while FX is held,** so the lights show only the routing.
- The change works like editing the drum's OUT parameter: the kit counts as changed, and saving the
  kit saves the new output.

## Delay

In the normal delay mode, each drum's echoes now sit where the drum is panned. A drum panned 30R echoes
at 30R; a centred drum echoes in the centre. Ping-pong mode works as in the official firmware.

- **In the official firmware, normal-mode echoes were always in the centre.** The delay added left
  and right together into one mono delay line. It now has a separate left and right line.
- **Echoes start at the drum's own level, about 6 dB quieter than before for a centred drum.** Adding
  left and right together made the official echoes louder than the dry sound. Turn up wet/dry or
  feedback to make up for it.
- **The longest delay is still about 742 ms.** The right line uses a second 64 kB buffer in the
  module's main memory.
- **With the FX bus on a mono output (L1, R1, L2 or R2), the echoes are the same as before.**

## CPU meter (temporary)

For testing the delay change. Will be removed or hidden before release.

Hold **SHIFT + FX** (either one first) to show how much of the time available for each audio block the module used:
- **CPU peak:** the slowest block since the meter was last closed. It closes when you let go of either button.
- **now:** the slowest block in the last quarter of a second, updated while you hold the buttons.

100% means the module only just finished a block in time. Above that, the audio crackles.

## Restart shortcut

Restarts the module without switching off the rack, for example to install an update.

1. Hold **DRUM** and the **encoder button** together for 3 seconds. The screen shows "Release DRUM to
   restart".
2. Release DRUM:
   - **Still holding the encoder:** the module restarts into the updater, as when the encoder is held
     at power-on.
   - **Encoder already released:** the module restarts normally.

Letting go of either button before the 3 seconds are up does nothing. After the message appears,
the restart can't be cancelled.

**Swapping the SD card while the module is on:** wait a few seconds after your last edit before taking
the card out, because kit edits are saved to the card 2 seconds after the last change. After putting
the new card in, restart straight away, without editing anything first. The module only opens the
card at start-up, so saving to the new card before a restart could damage the files on it.

## Fixes

- **MOD updates the screen when pressed.** In the official firmware, pressing MOD switches the mod
  matrix slot straight away, but the screen only showed the new slot when the button was released.
- **EDIT leaves the LFO page.** In the official firmware, pressing EDIT on the LFO page kept you on the
  LFO page with the EDIT light on. It now goes to the drum's first sub page.
- **Mod matrix sources are numbered.** The three mod matrix sources show as **SR1**, **SR2** and **SR3**
  instead of three identical "SRC" labels.
- **Drum 7's LFO target is looked up correctly.** The official firmware reads past the end of the LFO
  target list when drum 7 is selected. Drum 7 now uses LFO 6's target, which is the LFO it plays.
- **Filters can't get stuck silent.** In the official firmware, a filter that got into a bad state
  (NaN) stayed silent until the module was switched off and on. You'd notice it most on the snare:
  with the filter on, its noise disappeared, even with a low-pass wide open. The check that should
  clear the bad state was removed by the compiler's speed settings. It works again now, for the
  snare, cymbal and hi-hat filters.
- **The delay echoes at maximum Time and Range.** In the official firmware, Time and Range both at
  127 gave no echo at all, because the delay length wrapped around to zero. It now gives the longest
  delay, about 742 ms. Every other setting sounds the same as before.
- **Switching the delay from normal to ping-pong no longer writes outside the delay's memory.** In
  the official firmware, the first echo after the switch could be written into the memory holding the
  audio output and FX settings. Found and fixed in OpenElixir-02 (custom LXR-02 firmware).
- **Pitch EG slope at 127 no longer silences the drum** (drums 1–3 and the snare). At 127 the slope
  became infinite and the drum went silent until the slope was turned down. 127 now gives the steepest
  slope, the same maximum as the amp EG. Every other setting sounds the same. From OpenElixir-02.
- **Loud snares clip instead of crackling.** With high volume and transient, the snare's output wrapped
  around from full positive to full negative, which sounds like a loud crackle. It now clips, like the
  other drums. From OpenElixir-02.
- **The compressor clips instead of crackling with the FX bus on a mono output** (L1, R1, L2 or R2).
  The stereo outputs already clipped. From OpenElixir-02.
- **The RAT distortion no longer reads past the end of its table** at full-scale input. That read
  used memory that is never set, which could put a bad value into the distortion. From OpenElixir-02.
- **Saving a kit shows "SD Card error" when the card write fails.** The official firmware always showed
  the save as successful and could leave the file open. The kit is still kept in the module's memory
  until it's switched off, so you can try saving again. The same applies to saving the morph kit.
- **A damaged "last used kit" file on the SD card no longer breaks start-up.** The module starts with
  kit 1 instead of reading past the end of the kit list.
