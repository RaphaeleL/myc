/*
 * main.c
 *
 * Entry point of the myc compiler. Parses command line arguments and
 * hands off to the compiler driver.
 */

#include <stdlib.h>
#include <stdio.h>

#include "../include/compiler/compiler.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <input file> [output file]\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* input_path  = argv[1];
    const char* output_path = argc > 2 ? argv[2] : "a.out";

    if (!compiler_compile(input_path, output_path)) {
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
