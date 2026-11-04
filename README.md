# Custom firmware for the Erica Synths LXR Eurorack module

Unofficial custom firmware for the LXR V2 Eurorack drum module, based on the official v1.51. It adds
shortcuts, perform-mode muting, a DJ filter, stereo delay echoes, an output limiter and bug fixes.
It is not made, approved or supported by Erica Synths.

Some of the features and fixes come from [OpenElixir-02](https://github.com/tunefish777/openelixir-02),
custom firmware for the LXR-02 desktop drum machine.

- **[MODIFICATIONS.md](MODIFICATIONS.md) lists every difference from the official firmware.**
- **Download:** [LXRE_V2_V1.51-c5.img](https://github.com/sawtoothwave/lxr-eurorack-app/releases/download/v1.51-c5/LXRE_V2_V1.51-c5.img)
  (latest version), then follow [Installing the update](#installing-the-update). Older versions are on the
  [releases page](https://github.com/sawtoothwave/lxr-eurorack-app/releases).

> **Licence and trademarks:** the firmware source code is free software under the GNU GPL version 3
> ([LICENSE](LICENSE)). The names **"Erica Synths" and "LXR"** and the **LXR hardware** are the property
> of Erica Synths and are **not** covered by this licence. Building and installing your own firmware is
> at your own risk: Erica Synths provides no support for self-built or modified firmware.
> See [NOTICE.md](NOTICE.md).

## Installing the update

1. Copy `LXRE_V2_V<version>.img` to the top folder of a FAT32 SD card and delete any older `LXRE*.img`
   files from it.
2. With the module powered off, insert the card, hold down the encoder button and power on. Keep
   holding until "LXR Updater" appears.
3. Wait for "Update OK!". The module restarts with the new firmware.

From 1.51-c2 on, you can do step 2 without switching off: hold DRUM and the encoder button for 3 seconds,
then release DRUM while still holding the encoder. See [MODIFICATIONS.md](MODIFICATIONS.md#restart-shortcut)
for what to watch out for when swapping the SD card with the module switched on.

The updater (bootloader) is never changed by an update, so a failed or interrupted update can simply be
repeated. The module's updater only looks for files named `LXRE*.img`, so desktop LXR update files on
the same card are ignored.

## About me

I'm an [electronic musician](https://www.mute-city.com) who makes glitchy melodic IDM/ambient/drum-and-bass using a combination of software (REAPER, Ableton Live) and hardware (Octatrack, eurorack, etc.).

You can find me on [Bandcamp](https://mute-city.bandcamp.com/), [Subvert](https://subvert.fm/mute-city), [YouTube](https://www.youtube.com/@Mute-City), and [Instagram](https://instagram.com/mute.city).

## Licence

Copyright (C) 2012-2026 Erica Synths. Licensed under the [GNU GPL version 3](LICENSE) (GPL-3.0-only)
with the additional permission and terms in [NOTICE.md](NOTICE.md): modified firmware must be marked as
modified and must not be presented as official Erica Synths firmware. The trademarks and the hardware
are not licensed. Third-party components (STMicroelectronics, Arm, ChaN FatFs) keep their own licences,
see [NOTICE.md](NOTICE.md#third-party-components).
