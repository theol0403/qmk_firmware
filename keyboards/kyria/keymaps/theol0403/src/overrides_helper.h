// this helper takes a override definition (defined by OVERRIDES_DEF) and converts it into qmk-compatible overrides

#define OVERRIDE_BASIC(name, ...) OVERRIDE(name, ko_make_basic(__VA_ARGS__))
#define OVERRIDE_LAYERS(name, ...) OVERRIDE(name, ko_make_with_layers(__VA_ARGS__))
#define OVERRIDE_LAYERS_NEGMODS(name, ...) OVERRIDE(name, ko_make_with_layers_and_negmods(__VA_ARGS__))
#define OVERRIDE_LAYERS_NEGMODS_OPTIONS(name, ...) OVERRIDE(name, ko_make_with_layers_negmods_and_options(__VA_ARGS__))

#define OVERRIDE(name, initializer) static const key_override_t override_##name = initializer;
OVERRIDES_DEF
#undef OVERRIDE

#define OVERRIDE(name, initializer) &override_##name,
const key_override_t **key_overrides = (const key_override_t *[]){OVERRIDES_DEF NULL};
#undef OVERRIDE
