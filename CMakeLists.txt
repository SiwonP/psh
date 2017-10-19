cmake_minimum_required( VERSION 3.0 )
project(psh)
file(
    GLOB_RECURSE
    source_files
    ./src/*
)
add_executable(
    psh
    psh.c
    ${source_files}
)
