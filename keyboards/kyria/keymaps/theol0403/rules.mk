ifndef HAND
HAND = RIGHT
endif

OLED_DRIVER_ENABLE = yes   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow

ifeq ($(HAND),RIGHT)
CFLAGS += -DMASTER_RIGHT

MOUSEKEY_ENABLE = yes # Mouse keys
AUTO_SHIFT_ENABLE = yes # Auto Shift

else ifeq ($(HAND),LEFT)
CFLAGS += -DMASTER_LEFT

endif

