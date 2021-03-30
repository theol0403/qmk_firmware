.PHONY: %
%:
	keymapviz -r keyboards/kyria/keymaps/theol0403/keymap.c -c keyboards/kyria/keymaps/theol0403/keymapviz.toml > /dev/null

OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
TAP_DANCE_ENABLE = no
CONSOLE_ENABLE = no

MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MOUSEKEY_ENABLE = no

KEY_OVERRIDE_ENABLE = yes
COMBO_ENABLE = yes

ifndef HAND
HAND = RIGHT
endif

ifeq ($(HAND),RIGHT)
CFLAGS += -DIS_LEFT=false
else ifeq ($(HAND),LEFT)
CFLAGS += -DIS_LEFT=true
endif

ifeq ($(strip $(COMBO_ENABLE)), yes)
	SRC += src/combos.c
endif

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
	SRC += src/oled.c
endif

ifeq ($(strip $(KEY_OVERRIDE_ENABLE)), yes)
	SRC += src/overrides.c
endif

SRC += src/smartcaps.c
SRC += src/timing.c

