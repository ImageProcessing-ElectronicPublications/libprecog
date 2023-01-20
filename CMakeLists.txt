cmake_minimum_required(VERSION 3.2.0)
project(precog)

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_RELEASE 0)
set(VERSION_PRECOG ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_RELEASE})

include_directories(
    src/lib
    src/lib/*/*
    src/lib/binarizations
    src/lib/balance
    src/lib/border_detection
    src/lib/deblur
    src/lib/denoise
    src/lib/deskew
    src/lib/detectors
    src/lib/thinning
)

set(CMAKE_CXX_STANDARD 11)

# Options
option(BUILD_SHARED_LIBS "solib" OFF)
option(BUILD_SAMPLES "sample programs" ON)
#option(BUILD_TESTS false)

file(GLOB_RECURSE HEADERS
  "src/lib/*/*.h"
  "src/lib/*.h"
)
file(GLOB_RECURSE SOURCES
  "src/lib/*/*.cpp"
  "src/lib/*.cpp"
  "src/lib/*/*.h"
  "src/lib/*.h"
)

#find_package(Leptonica)
find_package(OpenCV)

#include_directories(${LEPTONICA_INCLUDE_DIR})
include_directories(${OpenCV_INCLUDE_DIRS})

message(STATUS "Build shared library: ${BUILD_SHARED_LIBS}")
if(${BUILD_SHARED_LIBS})
    add_library(precog SHARED ${SOURCES})
    set_target_properties(precog PROPERTIES VERSION ${VERSION_PRECOG} SOVERSION ${VERSION_MAJOR})
else()
    add_library(precog STATIC ${SOURCES})
endif()

target_link_libraries(precog
    ${OpenCV_LIBS}
    #${LEPTONICA_LIBRARY}
    lept
)

# Building samples
message(STATUS "Build samples: ${BUILD_SAMPLES}")
if(${BUILD_SAMPLES})
    add_subdirectory(src/samples)
endif()

install(FILES ${HEADERS}
        DESTINATION ${CMAKE_INSTALL_PREFIX})
