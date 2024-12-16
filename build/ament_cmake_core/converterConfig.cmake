# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_converter_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED converter_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(converter_FOUND FALSE)
  elseif(NOT converter_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(converter_FOUND FALSE)
  endif()
  return()
endif()
set(_converter_CONFIG_INCLUDED TRUE)

# output package information
if(NOT converter_FIND_QUIETLY)
  message(STATUS "Found converter: 0.0.0 (${converter_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'converter' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${converter_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(converter_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${converter_DIR}/${_extra}")
endforeach()
