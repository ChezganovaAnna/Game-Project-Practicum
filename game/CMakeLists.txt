project(game)

find_package(Freetype REQUIRED)
find_package(JPEG REQUIRED)
find_package(SFML 2 COMPONENTS window graphics system REQUIRED)

file(GLOB_RECURSE SRC "*.h" "*.cpp")
add_executable(game ${SRC})
target_include_directories(game PRIVATE ${SFML_INCLUDE_DIR} ${JPEG_INCLUDE_DIR} ${FREETYPE_INCLUDE_DIRS})
target_compile_features(game PUBLIC cxx_std_17)
target_compile_definitions(game PRIVATE SFML_STATIC)
target_link_libraries(game ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} ${JPEG_LIBRARIES} ${FREETYPE_LIBRARIES})
