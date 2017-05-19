add_executable(sprite_builder ./sprite_builder.cpp)
target_link_libraries(sprite_builder jsoncpp_lib_static)

add_custom_command(
    TARGET sprite_builder
    COMMAND sprite_builder
    )

set_property(
    DIRECTORY
    APPEND
    PROPERTY ADDITIONAL_MAKE_CLEAN_FILES "fonts.json" "sprites.json"
    )
