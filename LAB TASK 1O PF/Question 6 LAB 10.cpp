#include <stdio.h>
#include <string.h>

char reverse(char s[], int start, int end) {
    if (start >= end) 
        return 0;
    int temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    reverse(s, start + 1, end - 1);
}

int main() {
    char s[100];
    fgets(s, 100, stdin);
    int length = strlen(s) - 1;
    reverse(s, 0, length);
    puts(s);
}

