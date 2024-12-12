#include <stdio.h>

int main() {
    char ch;
    int lines = 0, spaces = 0, tabs = 0;

    printf("Enter a paragraph \n");
    
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            lines++;
        }
        else if (ch == ' ') {
            spaces++;
        }
        else if (ch == '\t') {
            tabs++;
        }
    }
    printf("\nResults:\n");
    printf("No. of lines: %d\n", lines);
    printf("No. of blank spaces: %d\n", spaces);
    printf("No. of tabs: %d\n", tabs);

    return 0;
}

