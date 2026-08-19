/*
 * diagnostics/diagnostics.c
 *
 * Error and warning reporting. Currently prints straight to stderr
 * and counts occurrences; source-snippet output can be added later.
 */

#include "../../include/diagnostics/diagnostics.h"

#include <stdio.h>

void diagnostics_init(Diagnostics* diags) {
    diags->error_count   = 0;
    diags->warning_count = 0;
}

void diagnostics_error(Diagnostics* diags, int line, int column, const char* message) {
    diags->error_count += 1;
    fprintf(stderr, "error: %d:%d: %s\n", line, column, message);
}

void diagnostics_warning(Diagnostics* diags, int line, int column, const char* message) {
    diags->warning_count += 1;
    fprintf(stderr, "warning: %d:%d: %s\n", line, column, message);
}

bool diagnostics_had_error(const Diagnostics* diags) {
    return diags->error_count > 0;
}
