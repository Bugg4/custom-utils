#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void usage(const char* program_name) {
    printf("Touch.exe implementation from Bulgarelli Marco, built 24/12/2024\n");
    printf("****************************************************************\n");
    printf("Usage: %s [options] filename(s)\n", program_name);
    printf("Options:\n");
    printf("  -v, --verbose    Enable verbose output\n");
}

int main(int argc, char** argv) {
    int verbose = 0;

    if (argc < 2) {
        usage(argv[0]);
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        // Check for verbose flags
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
            verbose = 1;
            continue;  // Skip further processing for this argument
        }

        char* filename = calloc(strlen(argv[i]) + 1, sizeof(char));
        if (!filename) {
            fprintf(stderr, "Memory allocation failed for filename.\n");
            return 1;
        }
        strcpy(filename, argv[i]);

        FILE* fp = fopen(filename, "a+");
        if (!fp) {
            fprintf(stderr, "Could not open file: %s\n", filename);
            free(filename);
            continue;  // Move to the next file
        }

        if (verbose) {
            printf("Created/Opened file: %s\n", filename);
        }

        fclose(fp);
        free(filename);
    }

    return 0;
}
