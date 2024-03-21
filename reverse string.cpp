#include <stdio.h>
#include <string.h>

void printReverse(char str[], int index) {
    if (index < 0) {
        return;
    }
    printf("%c", str[index]);
    printReverse(str, index - 1);
}

int main() {
    char str[] = "Saveetha";
    int length = strlen(str);
    printReverse(str, length - 1);
    printf("\n");
    return 0;
}
