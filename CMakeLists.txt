cmake_minimum_required(VERSION 3.14)

project(unpacker_data_products_nalu VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# Suppress false-positive GCC warnings when top-level
if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
  if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    add_compile_options(-Wno-stringop-overflow)
  endif()
endif()


include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# ------------------ CPM Setup ------------------
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CPM.cmake)

# Required system packages
find_package(ROOT REQUIRED COMPONENTS Core RIO)
find_package(unpacker_data_products_core REQUIRED)
include(${ROOT_USE_FILE})

# Source files
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Includes and linking
target_include_directories(${PROJECT_NAME}
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
    ROOT::Core ROOT::RIO
    unpacker_data_products_core::unpacker_data_products_core
)

# Helper function to gather include dirs from targets for ROOT dictionary
function(append_target_includes_to_root_dict target_name)
  get_target_property(INCLUDE_DIRS ${target_name} INTERFACE_INCLUDE_DIRECTORIES)
  if(INCLUDE_DIRS AND NOT INCLUDE_DIRS STREQUAL "${target_name}_NOTFOUND")
    foreach(dir IN LISTS INCLUDE_DIRS)
      if(dir MATCHES "^\\$<BUILD_INTERFACE:(.+)>$")
        set(actual "${CMAKE_MATCH_1}")
        if(EXISTS "${actual}")
          list(APPEND ROOT_DICTIONARY_INCLUDE_OPTIONS "-I${actual}")
        endif()
      elseif(NOT dir MATCHES "^\\$")  # Skip generator expressions
        if(EXISTS "${dir}")
          list(APPEND ROOT_DICTIONARY_INCLUDE_OPTIONS "-I${dir}")
        endif()
      endif()
    endforeach()
  endif()
  set(ROOT_DICTIONARY_INCLUDE_OPTIONS ${ROOT_DICTIONARY_INCLUDE_OPTIONS} PARENT_SCOPE)
endfunction()

# ROOT Dictionary
set(ROOT_LINKDEF ${CMAKE_CURRENT_SOURCE_DIR}/include/LinkDef.h)
set(ROOT_DICTIONARY_INCLUDE_OPTIONS "-I${CMAKE_CURRENT_SOURCE_DIR}/include")

# Add include dirs from analysis pipeline core
append_target_includes_to_root_dict(unpacker_data_products_core::unpacker_data_products_core)

# Gather all headers for dictionary
file(GLOB_RECURSE STAGE_HEADERS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/include/stages/*.h)
file(GLOB_RECURSE DATAPRODUCT_HEADERS CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/include/data_products/*.h)

set(ALL_DICT_HEADERS ${STAGE_HEADERS} ${DATAPRODUCT_HEADERS})
list(FILTER ALL_DICT_HEADERS EXCLUDE REGEX "LinkDef\\.h$")

# Generate ROOT dictionary
ROOT_GENERATE_DICTIONARY(G__${PROJECT_NAME}
  ${ALL_DICT_HEADERS}
  LINKDEF ${ROOT_LINKDEF}
  OPTIONS ${ROOT_DICTIONARY_INCLUDE_OPTIONS} -Wno-inconsistent-missing-override
)

# Add the generated dictionary source to the library sources
target_sources(${PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}/G__${PROJECT_NAME}.cxx
)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})  # for generated headers

# Install rules (if top-level)
if(CMAKE_SOURCE_DIR STREQUAL PROJECT_SOURCE_DIR)
  install(TARGETS ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}Targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )

  
  install(DIRECTORY inc
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )

  install(EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}
  )

  write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
  )

  configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
  )

  install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
  )
endif()
