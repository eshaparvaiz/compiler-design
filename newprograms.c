#CProgramtoCounttheNumberofLines(Including Blank Lines)

#include <stdio.h>
int main() {
    FILE *file = fopen("input.c", "r");
    int lines = 0;
    char ch;
    if (file) {
        while ((ch = fgetc(file)) != EOF) {
            if (ch == '\n') lines++;
        }
        fclose(file);
    }
    printf("%d\n", lines + 1);
    return 0;
}


#CProgramtoCountOnlyNon-EmptyLines

#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("input.c", "r");
    int lines = 0;
    char line[1000];
    if (file) {
        while (fgets(line, sizeof(line), file)) {
            if (strspn(line, " \t\r\n") != strlen(line)) lines++;
        }
        fclose(file);
    }
    printf("%d\n", lines);
    return 0;
}


#CProgramtoCountCommentLinesinaCProgram

#include <stdio.h>
#include <string.h>

int main() {
    FILE *file = fopen("input.c", "r");
    int count = 0, in_comment = 0;
    char line[1000];
    if (file) {
        while (fgets(line, sizeof(line), file)) {
            if (strstr(line, "//")) count++;
            if (strstr(line, "/*")) in_comment = 1;
            if (in_comment) count++;
            if (strstr(line, "*/")) in_comment = 0;
        }
        fclose(file);
    }
    printf("%d\n", count);
    return 0;
}


#C Program to Tokenize a Program File and Categorize Tokens

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *keywords[] = {"int", "return", "if", "else", "while", "for", "char", "float", "double", "void"};
int is_keyword(char *word) {
    for (int i = 0; i < 10; i++) if (strcmp(word, keywords[i]) == 0) return 1;
    return 0;
}

int main() {
    FILE *file = fopen("input.c", "r");
    char word[50];
    if (file) {
        while (fscanf(file, "%s", word) != EOF) {
            if (is_keyword(word)) printf("Keyword: %s\n", word);
            else if (isdigit(word[0])) printf("Constant: %s\n", word);
            else printf("Identifier: %s\n", word);
        }
        fclose(file);
    }
    return 0;
}


#C Program to Tokenize a Given Code Snippet (Keywords, Identifiers, Operators)

#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *keywords[] = {"int", "if", "else", "while", "return", "char", "void"};
char *operators = "+-*/=%";

int is_keyword(char *word) {
    for (int i = 0; i < 7; i++) if (strcmp(word, keywords[i]) == 0) return 1;
    return 0;
}

int is_operator(char ch) {
    return strchr(operators, ch) != NULL;
}

int main() {
    char code[1000], *token;
    fgets(code, sizeof(code), stdin);
    token = strtok(code, " \t\n;(),{}");
    while (token) {
        if (is_keyword(token)) printf("Keyword: %s\n", token);
        else if (isdigit(token[0])) printf("Constant: %s\n", token);
        else if (is_operator(token[0])) printf("Operator: %s\n", token);
        else printf("Identifier: %s\n", token);
        token = strtok(NULL, " \t\n;(),{}");
    }
    return 0;
}



#C Program to Check if an Entered String is a Valid Identifier in C

#include <stdio.h>
#include <ctype.h>

int is_valid_identifier(char *str) {
    if (!isalpha(str[0]) && str[0] != '_') return 0;
    for (int i = 1; str[i]; i++)
        if (!isalnum(str[i]) && str[i] != '_') return 0;
    return 1;
}

int main() {
    char str[100];
    scanf("%s", str);
    printf("%s\n", is_valid_identifier(str) ? "Valid" : "Invalid");
    return 0;
}