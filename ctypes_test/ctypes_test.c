#include <stdio.h>
#include "ctypes_test.h"


int remove_char(char text[], char symbol, int n) {
    // remove 'n' first instances of 'symbol' in 'text'
    char *reader = text;
    char *writer = text;
    int count = 0;
    for (; *reader != '\0'; reader++) {
        if (*reader== symbol && count < n) {
            count++;
            reader++;
        }
        *writer = *reader;
        writer++;
    }
    if (count > 0) *writer = '\0';

    return count;
}

long long iterate(long long times) {
    long long i = 0, j = 1, k = 2;
    while (i < times) {
        i = k;
        k += j;
        j = i;
    }

    return k;
}

/*int main(int argc, char** argv) {
    char text[] = "terererere";
    remove_char(text, 'e', 3);
    printf("%s", text);
    return 0;
}*/
