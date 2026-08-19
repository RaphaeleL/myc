/*
 * lexer/lexer.c
 *
 * Tokenizer implementation. Scans the source buffer character by
 * character and produces the token stream. 
 */

#include "../../include/lexer/lexer.h"

TokenList lexer_tokenize(const Source* source, Diagnostics* diags) {
    (void) source;
    (void) diags;

    TokenList tokens;
    token_list_init(&tokens);

    /* TODO: tokenize source->data */

    return tokens;
}
