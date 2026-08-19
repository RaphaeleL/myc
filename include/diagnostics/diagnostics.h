/*
 * diagnostics/diagnostics.h
 *
 * Central error and warning reporting. Every compiler stage (lexer,
 * parser, sema, codegen) reports through this interface so the driver
 * can decide after each stage whether to continue or abort.
 */

#ifndef MYC_DIAGNOSTICS_DIAGNOSTICS_H
#define MYC_DIAGNOSTICS_DIAGNOSTICS_H

#include <stdbool.h>

typedef struct {
    int error_count;
    int warning_count;
} Diagnostics;

/*
 * Resets both counters to zero. Must be called before the first report.
 */
void diagnostics_init(Diagnostics* diags);

/*
 * Reports an error at the given source position (1-based line/column)
 * to stderr and increments the error count.
 */
void diagnostics_error(Diagnostics* diags, int line, int column, const char* message);

/*
 * Reports a warning at the given source position (1-based line/column)
 * to stderr and increments the warning count. Warnings never abort
 * the compilation.
 */
void diagnostics_warning(Diagnostics* diags, int line, int column, const char* message);

/*
 * Returns true if at least one error has been reported. The driver
 * checks this after each stage to stop the pipeline early.
 */
bool diagnostics_had_error(const Diagnostics* diags);

#endif /* MYC_DIAGNOSTICS_DIAGNOSTICS_H */
