/*
 * parser/parser.c
 *
 * Parser implementation. Turns the token stream into an AST.
 * 
 */

#include "../../include/parser/parser.h"

AstNode* parser_parse(const TokenList* tokens, Diagnostics* diags) {
    (void) tokens;
    (void) diags;

    /* TODO: parse tokens into an AST */

    return ast_new(AST_NONE);
}
