#include <stdio.h>
#include <string.h>
int is_keyword(char str[]) {
    char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do", "int", "long", "register", "return", 
        "short", "signed", "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", 
        "while"
    };
    int num_keywords = sizeof(keywords) / sizeof(keywords[0]);
int i=0;
    for ( i = 0; i < num_keywords; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;  
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = 0;

    if (is_keyword(str)) {
        printf("\"%s\" is a C keyword.\n", str);
    } else {
        printf("\"%s\" is not a C keyword.\n", str);
    }

    return 0;
}

