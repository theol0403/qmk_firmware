// this helper takes an override definition (defined by OVERRIDE_DEF) and converts it into qmk-compatible override syntax

#define OVERRIDE_BASIC(name, ...) OVERRIDE(name, ko_make_basic(__VA_ARGS__))
#define OVERRIDE_LAYERS(name, ...) OVERRIDE(name, ko_make_with_layers(__VA_ARGS__))
#define OVERRIDE_LAYERS_NEGMODS(name, ...) OVERRIDE(name, ko_make_with_layers_and_negmods(__VA_ARGS__))
#define OVERRIDE_LAYERS_NEGMODS_OPTIONS(name, ...) OVERRIDE(name, ko_make_with_layers_negmods_and_options(__VA_ARGS__))

#define OVERRIDE(name, initializer) static const key_override_t override_##name = initializer;
OVERRIDE_DEF
#undef OVERRIDE

#ifndef OVERRIDE_EXTRA
#  define OVERRIDE_EXTRA
#endif

#define OVERRIDE(name, initializer) &override_##name,
const key_override_t **key_overrides = (const key_override_t *[]){OVERRIDE_DEF OVERRIDE_EXTRA NULL};
#undef OVERRIDE
