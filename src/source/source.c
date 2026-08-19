/*
 * source/source.c
 *
 * Source file loading. Reads a file from disk into a single
 * null-terminated heap buffer that the rest of the compiler
 * points into.
 */

#include "../../include/source/source.h"

#include <stdio.h>
#include <stdlib.h>

bool source_load(Source* source, const char* path) {
    source->path   = path;
    source->data   = NULL;
    source->length = 0;

    FILE* file = fopen(path, "rb");
    if (!file) {
        return false;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (size < 0) {
        fclose(file);
        return false;
    }

    char* data = malloc((size_t) size + 1);
    if (!data) {
        fclose(file);
        return false;
    }

    size_t read = fread(data, 1, (size_t) size, file);
    fclose(file);

    if (read != (size_t) size) {
        free(data);
        return false;
    }

    data[size] = '\0';

    source->data   = data;
    source->length = (size_t) size;
    return true;
}

void source_free(Source* source) {
    free(source->data);
    source->data   = NULL;
    source->length = 0;
}
