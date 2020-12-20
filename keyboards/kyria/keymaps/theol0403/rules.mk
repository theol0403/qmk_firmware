ifndef HAND
HAND = RIGHT
endif

OLED_DRIVER_ENABLE = no   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
MOUSEKEY_ENABLE = no# Mouse keys
COMBO_ENABLE = yes

ifeq ($(HAND),RIGHT)
CFLAGS += -DMASTER_RIGHT
else ifeq ($(HAND),LEFT)
CFLAGS += -DMASTER_LEFT
endif

