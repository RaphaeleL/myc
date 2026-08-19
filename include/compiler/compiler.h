/*
 * compiler/compiler.h
 *
 * The compiler driver. Owns the whole pipeline and its intermediate
 * results; main() should only need this header.
 */

#ifndef MYC_COMPILER_COMPILER_H
#define MYC_COMPILER_COMPILER_H

#include <stdbool.h>

/*
 * Compiles the file at `input_path` into a binary at `output_path`,
 * running the full pipeline: source -> lexer -> parser -> sema ->
 * codegen. Stops after the first stage that reports errors.
 *
 * All errors are printed to stderr along the way. Returns true if the
 * whole pipeline succeeded, false otherwise.
 */
bool compiler_compile(const char* input_path, const char* output_path);

#endif /* MYC_COMPILER_COMPILER_H */
