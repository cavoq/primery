cmake_minimum_required(VERSION 3.16)

project(primery
    VERSION 1.3
    DESCRIPTION "Prime number generator with multiple algorithms"
    LANGUAGES CXX
)

# Require C++17 for std::execution
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate compile_commands.json for IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Source files
set(SOURCES
    main.cpp
    src/argumentparser.cpp
    src/argumentvalidator.cpp
    src/config.cpp
    src/multithreadedprimegenerator.cpp
    src/result.cpp
    src/singlethreadedprimegenerator.cpp
    src/timer.cpp
    src/utils.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Compiler warnings and optimization
target_compile_options(${PROJECT_NAME} PRIVATE
    -O3
    -Wall
    -Wextra
    -Wpedantic
)

# Link TBB for parallel execution policies (required on some systems)
find_package(TBB QUIET)
if(TBB_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE TBB::tbb)
endif()

# Installation - simply installs binary to /usr/local/bin (or custom prefix)
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)

# CPack configuration for creating packages
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY ${PROJECT_DESCRIPTION})
set(CPACK_PACKAGE_CONTACT "maintainer@example.com")
set(CPACK_GENERATOR "TGZ;DEB")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "libc6")
include(CPack)
