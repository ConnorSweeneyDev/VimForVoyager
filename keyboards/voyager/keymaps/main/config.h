/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/

#undef TAPPING_TERM
#define TAPPING_TERM 135

#define USB_SUSPEND_WAKEUP_DELAY 0
#define CAPS_LOCK_STATUS
#define SERIAL_NUMBER "NYBN6/ba3g5"
#define FIRMWARE_VERSION u8"NYBN6/Mm3zX"
#define LAYER_STATE_8BIT
#define HCS(report) host_consumer_send(record->event.pressed ? report : 0); return false

#define RGB_MATRIX_STARTUP_SPD 60

#define BETTER_VISUAL_MODE //
#define VIM_I_TEXT_OBJECTS //
#define VIM_A_TEXT_OBJECTS //
#define VIM_G_MOTIONS      // MANUALLY ADDED
#define VIM_PASTE_BEFORE   //
#define VIM_REPLACE        //
#define VIM_NUMBERED_JUMPS //
