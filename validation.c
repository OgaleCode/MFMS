#include <stdio.h>
#include <string.h>
#include "validation.h"

static void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int getValidInt(int min, int max, const char* prompt) {
    int value, matches;
    do {
        printf("%s", prompt);
        matches = scanf("%d", &value);
        clearBuffer();
        if (matches != 1 || value < min || value > max) {
            printf("❌ Invalid choice. Try again.\n");
        } else {
            return value;
        }
    } while (1);
}

float getValidFloat(float min, float max, const char* prompt) {
    float value;
    int matches;
    do {
        printf("%s", prompt);
        matches = scanf("%f", &value);
        clearBuffer();
        if (matches != 1 || value < min || value > max) {
            printf("❌ Invalid amount. Try again.\n");
        } else {
            return value;
        }
    } while (1);
}

void getValidString(char* output, int maxLength, const char* prompt) {
    do {
        printf("%s", prompt);
        if (fgets(output, maxLength, stdin) != NULL) {
            output[strcspn(output, "\n")] = 0;
            if (strlen(output) == 0) {
                printf("❌ Field cannot be blank.\n");
            } else {
                break;
            }
        }
    } while (1);
}
