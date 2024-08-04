# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
ORYX_ENABLE = yes
RGB_MATRIX_CUSTOM_KB = yes
TAP_DANCE_ENABLE = yes
SPACE_CADET_ENABLE = no

SRC += qmk-vim/src/mac_mode.c         #
SRC += qmk-vim/src/process_func.c     #
SRC += qmk-vim/src/numbered_actions.c #
SRC += qmk-vim/src/motions.c          # MANUALLY ADDED
SRC += qmk-vim/src/actions.c          #
SRC += qmk-vim/src/modes.c            #
SRC += qmk-vim/src/vim.c              #
