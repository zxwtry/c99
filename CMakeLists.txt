cmake_minimum_required(VERSION 3.8)
project(c99)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c b01_c_primer_plus/b01_p025_two_func.c b01_c_primer_plus/b01_p029_c_keyword.c b01_c_primer_plus/b01_p034_datastruct_keyword.c b01_c_primer_plus/b01_p038_radix.c b01_c_primer_plus/b01_p042_char.c)
add_executable(c99 ${SOURCE_FILES})