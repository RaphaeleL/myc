/*
 * lexer/lexer.h
 *
 * The tokenizer. First stage of the pipeline: turns the raw source
 * text into a flat list of tokens for the parser to consume.
 */

#ifndef MYC_LEXER_LEXER_H
#define MYC_LEXER_LEXER_H

#include "../source/source.h"
#include "token.h"
#include "../diagnostics/diagnostics.h"

/*
 * Scans the whole source buffer and returns the token stream,
 * terminated by a TOKEN_EOF token.
 *
 * Lexical errors (invalid characters, unterminated strings, ...) are
 * reported to `diags`; the lexer keeps scanning after an error so all
 * problems are reported in one run.
 *
 * The caller owns the returned list and must free it with
 * token_list_free(). Tokens point into `source->data`.
 */
TokenList lexer_tokenize(const Source* source, Diagnostics* diags);

#endif /* MYC_LEXER_LEXER_H */
