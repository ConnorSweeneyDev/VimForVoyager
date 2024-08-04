# VimForVoyager
Instructions specifically for adding a toggleable Vim mode to the ZSA Voyager on Windows.

## Pre-requisites
- Windows.
- ZSA Voyager keyboard (although can be adapted to other QMK keyboards).
- WSL2 with a fresh or clean install of Ubuntu 22.04.

## Installation
Start by entering Ubuntu 22.04 and running the following commands:
- `sudo apt update && sudo apt upgrade -y`
- `sudo apt install git g++ make llvm clang python3-pip chromium-bsu chromium-browser unzip`
- `git clone https://github.com/ConnorSweeneyDev/VimForVoyager.git && cd VimForVoyager`

Next, install the QMK CLI like so:
- `python3 -m pip install --user qmk`
- `echo 'PATH="$HOME/.local/bin:$PATH"' >> $HOME/.bashrc && source $HOME/.bashrc`
- `qmk setup -H ~/VimForVoyager -b main` - Say yes to any prompts and run `qmk hello` to
  verify the installation.

This repository is a modified version of ZSA's QMK fork that has a `main` keymap for the voyager
that has a Vim mode (using [this](https://configure.zsa.io/voyager/layouts/NYBN6/latest/0) as the
base). To use it now you can run `qmk compile -kb voyager -km main`, then move the
`voyager_main.bin` file to your Windows machine and select the "Flash" button in the Keymapp app to
select the file and flash the firmware.

## Customization
If you want your own mappings (you do), you can replace `keymap.c`, `config.h` and `rules.mk` in the
`keyboards/voyager/keymaps/main` directory with your own, running the same compile command and
flashing the firmware in the same way as above afterwards. This process goes as follows:
- Create a configuration using [Oryx](https://configure.zsa.io/home).
- Open the configuration in linux using the `chromium-browser` command.
- Download the source code for the configuration using the "Download Source" button.
- Find the zip file in the `~/snap/chromium/[NUMBER]/Downloads` directory.
- Unzip the file using `unzip [FILE]` and move the `keymap.c`, `config.h`, and `rules.mk` files to
  the `~/zsa/qmk_firmware/keyboards/voyager/keymaps/main` directory to replace the existing ones.
- Manually add all the code that is marked "Manually Added" in my fork to your own `keymap.c`,
  `config.h`, and `rules.mk` files.
- Run `qmk clean`, then compile and flash the firmware as above.

## Credit

- [ZSA's QMK fork](https://github.com/zsa/qmk_firmware) for the base firmware.
- [QMK-Vim](https://github.com/andrewjrae/qmk-vim) for the vim integration.
