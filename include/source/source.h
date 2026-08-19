/*
 * source/source.h
 *
 * Source file handling. Loads a source file from disk into memory and
 * keeps it alive for the duration of the compilation; tokens and AST
 * nodes point directly into this buffer instead of copying strings.
 */

#ifndef MYC_SOURCE_SOURCE_H
#define MYC_SOURCE_SOURCE_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    const char* path;
    char*       data;
    size_t      length;
} Source;

/*
 * Reads the entire file at `path` into memory.
 *
 * On success, fills `source` with a heap-allocated, null-terminated
 * buffer (`data`) and its size in bytes (`length`, excluding the
 * terminator) and returns true.
 *
 * On failure (file not found, not readable, out of memory), leaves
 * `source` zeroed and returns false.
 */
bool source_load(Source* source, const char* path);

/*
 * Frees the buffer owned by `source` and resets it. Safe to call on a
 * zeroed/already-freed Source. Invalidates all tokens pointing into it.
 */
void source_free(Source* source);

#endif /* MYC_SOURCE_SOURCE_H */
