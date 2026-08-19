/*
 * codegen/codegen.c
 *
 * Code generation implementation: lowers the typed AST to native
 * code. 
 */

#include "../../include/codegen/codegen.h"

bool codegen_emit(const AstNode* ast, const char* output_path, Diagnostics* diags) {
    (void) ast;
    (void) output_path;
    (void) diags;

    /* TODO: emit native code */

    return true;
}
