file(GLOB SOURCE_FILES ./*.cpp)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(
    ${PROJECT_NAME}
    ${SDL2PP_LIBRARIES}
    jsoncpp_lib_static
    )

install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
    )
