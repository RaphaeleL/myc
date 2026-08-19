/*
 * parser/parser.h
 *
 * The parser. Second stage of the pipeline: consumes the token stream
 * produced by the lexer and builds the AST.
 */

#ifndef MYC_PARSER_PARSER_H
#define MYC_PARSER_PARSER_H

#include "../lexer/token.h"
#include "../ast/ast.h"
#include "../diagnostics/diagnostics.h"

/*
 * Parses the token stream into an AST and returns the root node.
 *
 * Syntax errors are reported to `diags`; the parser tries to recover
 * and continue so multiple errors can be reported in one run. The
 * returned tree may be partial if errors occurred — the caller must
 * check diagnostics_had_error() before using it.
 *
 * The caller owns the returned tree and must free it with ast_free().
 */
AstNode* parser_parse(const TokenList* tokens, Diagnostics* diags);

#endif /* MYC_PARSER_PARSER_H */
