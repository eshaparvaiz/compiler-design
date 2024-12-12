#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100

int is_valid_identifier(char str[]) {

    if (!(isalpha(str[0]) || str[0] == '_')) {
        return 0; 
    }

int i=0;
    for (i = 1; i < strlen(str); i++) {
        if (!(isalnum(str[i]) || str[i] == '_')) {
            return 0;
        }
    }
    char *keywords[] = {
        "int", "float", "double", "char", "void", "return", "if", "else", "while", "for", "switch", "case", "break", "continue"
    };
    for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 0;
        }
    }

    return 1;
}

int main() {
    char str[MAX_LEN];
    printf("Enter a string: ");
    fgets(str, MAX_LEN, stdin);
    str[strcspn(str, "\n")] = 0;

    if (is_valid_identifier(str)) {
        printf("\"%s\" is a valid identifier.\n", str);
    } else {
        printf("\"%s\" is not a valid identifier.\n", str);
    }

    return 0;
}

