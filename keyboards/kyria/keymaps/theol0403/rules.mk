.PHONY: %
%:
	 cat keyboards/kyria/keymaps/theol0403/keymap.c | go run keyboards/kyria/keymaps/theol0403/main.go > /tmp/layout.c && mv /tmp/layout.c keyboards/kyria/keymaps/theol0403/keymap.c | keymapviz -r keyboards/kyria/keymaps/theol0403/keymap.c -c keyboards/kyria/keymaps/theol0403/keymapviz.toml > /dev/null

# required
RGBLIGHT_ENABLE = yes    
ENCODER_ENABLE = yes      
OLED_DRIVER_ENABLE = yes   

# disable
CONSOLE_ENABLE = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no

# off by default
TAP_DANCE_ENABLE = no
MOUSEKEY_ENABLE = no


ifndef HAND
HAND = RIGHT
endif

ifeq ($(HAND),RIGHT)
# right master
KEY_OVERRIDE_ENABLE = yes
COMBO_ENABLE = yes
MOUSEKEY_ENABLE = yes
CFLAGS += -DIS_LEFT=false
else ifeq ($(HAND),LEFT)
# left slave
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

