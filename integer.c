#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid_signed_constant(const char *str) {
    if (str == NULL || *str == '\0') {
        return 0;
    }

    if (*str == '+' || *str == '-') {
        str++;
    }

    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

int is_valid_unsigned_constant(const char *str) {
    if (str == NULL || *str == '\0') {
        return 0; 
    }
    while (*str) {
        if (!isdigit(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}
int main() {
    char input[100];
    printf("Enter a constant (signed or unsigned): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;

    if (is_valid_signed_constant(input)) {
        printf("The input is a valid signed constant.\n");
    } else if (is_valid_unsigned_constant(input)) {
        printf("The input is a valid unsigned constant.\n");
    } else {
        printf("The input is not a valid constant.\n");
    }

    return 0;
}

