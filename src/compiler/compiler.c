/*
 * compiler/compiler.c
 *
 * Compiler driver implementation. Runs the pipeline stage by stage,
 * checks diagnostics between stages and owns the cleanup of all
 * intermediate results (source buffer, token list, AST).
 */

#include "../../include/compiler/compiler.h"

#include <stdio.h>

#include "../../include/source/source.h"
#include "../../include/lexer/lexer.h"
#include "../../include/parser/parser.h"
#include "../../include/sema/typecheck.h"
#include "../../include/codegen/codegen.h"
#include "../../include/diagnostics/diagnostics.h"

bool compiler_compile(const char* input_path, const char* output_path) {
    Diagnostics diags;
    diagnostics_init(&diags);

    Source source;
    if (!source_load(&source, input_path)) {
        fprintf(stderr, "error: could not read file '%s'\n", input_path);
        return false;
    }

    bool ok = false;

    TokenList tokens = lexer_tokenize(&source, &diags);
    if (diagnostics_had_error(&diags)) goto cleanup_tokens;

    AstNode* ast = parser_parse(&tokens, &diags);
    if (diagnostics_had_error(&diags)) goto cleanup_ast;

    if (!typecheck(ast, &diags)) goto cleanup_ast;

    if (!codegen_emit(ast, output_path, &diags)) goto cleanup_ast;

    ok = !diagnostics_had_error(&diags);

cleanup_ast:
    ast_free(ast);
cleanup_tokens:
    token_list_free(&tokens);
    source_free(&source);
    return ok;
}
