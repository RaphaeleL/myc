/*
 * sema/typecheck.h
 *
 * Semantic analysis. Third stage of the pipeline: resolves names,
 * checks types and annotates the AST so codegen can rely on a fully
 * typed, valid tree.
 */

#ifndef MYC_SEMA_TYPECHECK_H
#define MYC_SEMA_TYPECHECK_H

#include <stdbool.h>

#include "../ast/ast.h"
#include "../diagnostics/diagnostics.h"

/*
 * Walks the AST, resolves symbols and checks all types. Annotates the
 * tree in place (hence non-const `ast`).
 *
 * Semantic errors (undefined names, type mismatches, ...) are reported
 * to `diags`. Returns true if the tree is semantically valid and safe
 * to hand to codegen, false otherwise.
 */
bool typecheck(AstNode* ast, Diagnostics* diags);

#endif /* MYC_SEMA_TYPECHECK_H */
