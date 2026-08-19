/*
 * lexer/token.h
 *
 * Token definitions and a growable token array. A Token does not own
 * its text: `start` points directly into the loaded Source buffer, so
 * tokens are only valid as long as the Source is alive.
 */

#ifndef MYC_LEXER_TOKEN_H
#define MYC_LEXER_TOKEN_H

#include <stddef.h>

typedef enum {
    TOKEN_EOF = 0,

    /* TODO: define the real token kinds once the syntax is settled */
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_STRING,

    TOKEN_KIND_COUNT
} TokenKind;

typedef struct {
    TokenKind   kind;
    const char* start;  /* points into Source.data, not owned */
    size_t      length;
    int         line;
    int         column;
} Token;

typedef struct {
    Token* tokens;
    size_t count;
    size_t capacity;
} TokenList;

/*
 * Initializes an empty token list (no allocation happens until the
 * first push).
 */
void token_list_init(TokenList* list);

/*
 * Appends `token` to the end of the list, growing the backing array
 * (doubling strategy) when it is full.
 */
void token_list_push(TokenList* list, Token token);

/*
 * Frees the backing array and resets the list to empty. The Source
 * buffer the tokens point into is NOT freed by this.
 */
void token_list_free(TokenList* list);

#endif /* MYC_LEXER_TOKEN_H */
