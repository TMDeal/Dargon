add_executable(sprite_builder ./sprite_builder.cpp)
target_link_libraries(sprite_builder jsoncpp_lib_static)
set(SPRITE_DATA_DIR "${SOURCE_DIR}/res/sprite_data")

add_custom_command(
    OUTPUT ${SPRITE_DATA_DIR}/fonts.json ${SPRITE_DATA_DIR}/sprites.json
    COMMAND sprite_builder ${SPRITE_DATA_DIR}/fonts.dat ${SPRITE_DATA_DIR}/fonts.json
    COMMAND sprite_builder ${SPRITE_DATA_DIR}/sprites.dat ${SPRITE_DATA_DIR}/sprites.json
    DEPENDS fonts.dat sprites.dat sprite_builder
    )

add_custom_target(build_sprites
    DEPENDS ${SPRITE_DATA_DIR}/fonts.json ${SPRITE_DATA_DIR}/sprites.json
    )

set_property(
    DIRECTORY
    APPEND
    PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "${SPRITE_DATA_DIR}/fonts.json" "${SPRITE_DATA_DIR}/sprites.json"
    )
