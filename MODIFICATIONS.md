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

## Start-up screen

The first line of the start-up screen reads **"Custom firmware"** instead of "Sonic Potions", as the
licence requires for modified firmware. The second line still shows the version.

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

## Fixes

- **MOD updates the screen when pressed.** In the official firmware, pressing MOD switches the mod
  matrix slot straight away, but the screen only showed the new slot when the button was released.
- **EDIT leaves the LFO page.** In the official firmware, pressing EDIT on the LFO page kept you on the
  LFO page with the EDIT light on. It now goes to the drum's first sub page.
- **Mod matrix sources are numbered.** The three mod matrix sources show as **SR1**, **SR2** and **SR3**
  instead of three identical "SRC" labels.
- **Drum 7's LFO target is looked up correctly.** The official firmware reads past the end of the LFO
  target list when drum 7 is selected. Drum 7 now uses LFO 6's target, which is the LFO it plays.
