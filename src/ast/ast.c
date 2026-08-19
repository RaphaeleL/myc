/*
 * ast/ast.c
 *
 * AST node allocation and destruction.
 */

#include "../../include/ast/ast.h"

#include <stdlib.h>

AstNode* ast_new(AstKind kind) {
    AstNode* node = calloc(1, sizeof(AstNode));
    node->kind = kind;
    return node;
}

void ast_free(AstNode* node) {
    /* TODO: free children once the node kinds exist */
    free(node);
}
