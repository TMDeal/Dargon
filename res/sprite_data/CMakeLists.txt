add_executable(sprite_builder ./sprite_builder.cpp)
target_link_libraries(sprite_builder jsoncpp_lib_static)

add_custom_command(
    OUTPUT fonts.json sprites.json
    COMMAND sprite_builder ${SOURCE_DIR}/res/sprite_data/fonts.dat fonts.json
    COMMAND sprite_builder ${SOURCE_DIR}/res/sprite_data/sprites.dat sprites.json
    DEPENDS fonts.dat sprites.dat sprite_builder
    )

add_custom_target(build_sprites
    DEPENDS fonts.json sprites.json
    )

set_property(
    DIRECTORY
    APPEND
    PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "fonts.json" "sprites.json"
    )
