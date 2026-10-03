#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <float.h>
#include "input.h"

static void discardRestOfLine(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int readInt(const char *prompt, int min, int max) {
    char line[128];
    char *end;
    long value;

    while (1) {
        printf("%s", prompt);

        if (!fgets(line, sizeof(line), stdin)) {
            printf("\nInput ended. Exiting.\n");
            exit(EXIT_FAILURE);
        }

        errno = 0;
        value = strtol(line, &end, 10);

        if (end == line || (*end != '\n' && *end != '\0') ||
            errno == ERANGE || value < min || value > max) {
            printf("Invalid input. Enter a whole number from %d to %d.\n", min, max);
            continue;
        }

        return (int)value;
    }
}

double readDouble(const char *prompt, double min, double max) {
    char line[128];
    char *end;
    double value;

    while (1) {
        printf("%s", prompt);

        if (!fgets(line, sizeof(line), stdin)) {
            printf("\nInput ended. Exiting.\n");
            exit(EXIT_FAILURE);
        }

        errno = 0;
        value = strtod(line, &end);

        if (end == line || (*end != '\n' && *end != '\0') ||
            errno == ERANGE || value != value ||
            value < min || value > max) {
            printf("Invalid input. Enter a number from %.2f to %.2f.\n", min, max);
            continue;
        }

        return value;
    }
}

void readNonEmptyString(const char *prompt, char *buffer, int size) {
    while (1) {
        printf("%s", prompt);

        if (!fgets(buffer, size, stdin)) {
            printf("\nInput ended. Exiting.\n");
            exit(EXIT_FAILURE);
        }

        if (strchr(buffer, '\n') == NULL)
            discardRestOfLine();

        buffer[strcspn(buffer, "\n")] = '\0';

        if (strlen(buffer) == 0) {
            printf("This field cannot be empty.\n");
            continue;
        }

        return;
    }
}
