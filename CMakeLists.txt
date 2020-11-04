cmake_minimum_required(VERSION 3.10)
project(ConwaysLife)

set(HEADER_FILES
        LifeSimulator.hpp
        Pattern.hpp
        PatternAcorn.hpp
        PatternBlinker.hpp
        PatternBlock.hpp
        PatternGlider.hpp
        PatternGosperGliderGun.hpp
        Renderer.hpp
        RendererConsole.hpp)

set(SOURCE_FILES
        LifeSimulator.cpp
        RendererConsole.cpp)

add_executable(ConwaysLife ${HEADER_FILES} ${SOURCE_FILES} main.cpp)

set_property(TARGET ConwaysLife PROPERTY CXX_STANDARD 17)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    set_target_properties(ConwaysLife PROPERTIES LINK_FLAGS "/STACK:10000000")
    target_compile_options(ConwaysLife PRIVATE /W4 /permissive-)
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_compile_options(ConwaysLife PRIVATE -Wall -Wextra -pedantic)
else()
    target_compile_options(ConwaysLife PRIVATE -Wall -Wextra -pedantic)
endif()
#
# Prepare a pre-build step to run clang-format over all the [ch]pp source files.
# Start by finding the location of the clang-format executable.
#
find_program(CLANG_FORMAT "clang-format")
if (CLANG_FORMAT)
    #
    # Need to take the simple source file locations used for the project and get their full
    # file system locations for use in putting together the clang-format command line
    #
    unset(SOURCE_FILES_PATHS)
    foreach(SOURCE_FILE ${HEADER_FILES} ${SOURCE_FILES} ${UNIT_TEST_FILES} main.cpp)
        get_source_file_property(WHERE ${SOURCE_FILE} LOCATION)
        set(SOURCE_FILES_PATHS ${SOURCE_FILES_PATHS} ${WHERE})
    endforeach()

    #
    # This creates the clang-format target/command
    #
    add_custom_target(
            ClangFormat
            COMMAND ${CLANG_FORMAT}
            -i
            -style=file
            ${SOURCE_FILES_PATHS}
    )
    #
    # This makes the clang-format target a dependency of the main GoogleTestIntro project
    #
    add_dependencies(ConwaysLife ClangFormat)
else()
    message("Unable to find clang-format")
endif()

