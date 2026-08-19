/*
 * lexer/token.c
 *
 * Token list implementation: a growable array with a doubling
 * capacity strategy.
 */

#include "../../include/lexer/token.h"

#include <stdlib.h>

void token_list_init(TokenList* list) {
    list->tokens   = NULL;
    list->count    = 0;
    list->capacity = 0;
}

void token_list_push(TokenList* list, Token token) {
    if (list->count == list->capacity) {
        list->capacity = list->capacity ? list->capacity * 2 : 64;
        list->tokens   = realloc(list->tokens, list->capacity * sizeof(Token));
    }
    list->tokens[list->count++] = token;
}

void token_list_free(TokenList* list) {
    free(list->tokens);
    list->tokens   = NULL;
    list->count    = 0;
    list->capacity = 0;
}
