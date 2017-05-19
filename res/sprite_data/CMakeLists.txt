file(GLOB SPRITE_DATA_INPUT ${SOURCE_DIR}/res/spriteData/*.dat)

add_custom_command(
    OUTPUT fonts.json sprites.json
    COMMAND ./build.py
    DEPENDS ${SPRITE_DATA_INPUT} build.py
    WORKING_DIRECTORY ${SOURCE_DIR}/res/sprite_data
    )


add_custom_target(sprites
    DEPENDS fonts.json sprites.json
    )

set_property(
    TARGET sprites
    APPEND
    PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "fonts.json" "sprites.json"
    )

add_custom_target(clean-res
    COMMAND rm fonts.json sprites.json
    WORKING_DIRECTORY ${SOURCE_DIR}/res
    )
