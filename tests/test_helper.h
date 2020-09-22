#ifndef REFLECTIONC_TEST_HELPER_H
#define REFLECTIONC_TEST_HELPER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static int error(const char *text) {
    fputs(text, stderr);
    exit(EXIT_FAILURE);
}

static bool str_not_equal(const char *a, const char *b) {
    // same pointer or both NULL
    if (a == b)
        return false;
    // only one is NULL
    if (!a || !b)
        return true;
    return strcmp(a, b) != 0;
}

static char *open_file_as_string(const char *filename) {
    char *text = NULL;
    FILE *file = fopen(filename, "r");
    if (file) {
        fseek(file, 0, SEEK_END);
        long length = ftell(file);
        fseek(file, 0, SEEK_SET);
        text = malloc(length);
        if (text)
            fread(text, 1, length, file);
        fclose(file);
    }
    return text;
}


#endif //REFLECTIONC_TEST_HELPER_H
