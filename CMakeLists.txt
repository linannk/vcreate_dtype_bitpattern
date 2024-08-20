cmake_minimum_required(VERSION 3.15)
project(vcreate_dtype_bitpattern
  LANGUAGES CXX C
  DESCRIPTION "")

include(CheckCXXCompilerFlag)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

if(CMAKE_CXX_COMPILER_ID STREQUAL GNU)
  check_cxx_compiler_flag(-fwrapv HAVE_FWRAPV)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fwrapv")

  check_cxx_compiler_flag(-fno-strict-aliasing HAVE_FNO_STRICT_ALIASING)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-strict-aliasing")
endif()

add_executable(vcreate_dtype_bitpattern vcreate_dtype_bitpattern.cc)

