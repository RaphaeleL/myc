/*
 * ast/ast_print.h
 *
 * Debug pretty-printer for the AST. Not part of the compilation
 * pipeline; only used to inspect what the parser produced.
 */

#ifndef MYC_AST_AST_PRINT_H
#define MYC_AST_AST_PRINT_H

#include "ast.h"

/*
 * Dumps the tree rooted at `node` to stdout in a human-readable,
 * indented form. Safe to call with NULL.
 */
void ast_print(const AstNode* node);

#endif /* MYC_AST_AST_PRINT_H */
