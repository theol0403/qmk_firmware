ifndef HAND
HAND = RIGHT
endif

OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
TAP_DANCE_ENABLE = no
CONSOLE_ENABLE = no

MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MOUSEKEY_ENABLE = no

SRC += combos.c
SRC += oled.c
SRC += smartcaps.c
SRC += timing.c

ifeq ($(HAND),RIGHT)
COMBO_ENABLE = yes
CFLAGS += -DIS_LEFT=false
else ifeq ($(HAND),LEFT)
CFLAGS += -DIS_LEFT=true
endif

