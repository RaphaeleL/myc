/*
 * ast/ast.h
 *
 * The abstract syntax tree. Node kinds and the node structure itself
 * are placeholders until the language syntax is settled; every node
 * carries its source position for diagnostics.
 */

#ifndef MYC_AST_AST_H
#define MYC_AST_AST_H

typedef enum {
    AST_NONE = 0,

    /* TODO: define the real node kinds once the syntax is settled */

    AST_KIND_COUNT
} AstKind;

typedef struct AstNode AstNode;

struct AstNode {
    AstKind kind;
    int     line;
    int     column;
};

/*
 * Allocates a zero-initialized node of the given kind on the heap.
 */
AstNode* ast_new(AstKind kind);

/*
 * Recursively frees `node` and all of its children. Safe to call
 * with NULL.
 */
void ast_free(AstNode* node);

#endif /* MYC_AST_AST_H */
