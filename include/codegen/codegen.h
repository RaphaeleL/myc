/*
 * codegen/codegen.h
 *
 * Code generation. Final stage of the pipeline: turns the typed AST
 * into native code and writes the output binary.
 */

#ifndef MYC_CODEGEN_CODEGEN_H
#define MYC_CODEGEN_CODEGEN_H

#include <stdbool.h>

#include "../ast/ast.h"
#include "../diagnostics/diagnostics.h"

/*
 * Generates native code for the typed AST and writes the result to
 * `output_path`. Expects a tree that passed typecheck().
 *
 * Backend errors are reported to `diags`. Returns true on success,
 * false if code generation or writing the output failed.
 */
bool codegen_emit(const AstNode* ast, const char* output_path, Diagnostics* diags);

#endif /* MYC_CODEGEN_CODEGEN_H */
