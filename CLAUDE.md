# QMK Firmware - Kyria rev1

## Keyboard

Splitkb Kyria rev1 with Elite-C controllers, Swedish layout.
Keymap lives at `keyboards/splitkb/kyria/keymaps/axeltlarsson/`.

## Building

```bash
nix develop
qmk compile -kb splitkb/kyria/rev1 -km axeltlarsson
```

## Flashing

Flash each half separately — press the reset button on the Elite-C to enter bootloader mode:

```bash
qmk flash -kb splitkb/kyria/rev1 -km axeltlarsson
```

Plug in one half, reset, wait for flash, then repeat for the other half.

First-time EEPROM handedness setup:

```bash
qmk flash -kb splitkb/kyria/rev1 -km axeltlarsson -bl dfu-split-left
qmk flash -kb splitkb/kyria/rev1 -km axeltlarsson -bl dfu-split-right
```

The `Error 254` from dfu-programmer after a successful write is normal — ignore it.

## CI

Push to the branch triggers `.github/workflows/build_kyria.yml` which builds firmware and uploads artifacts.
