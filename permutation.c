/**
 * permutation.c
 * @author Wang Guibao (https://github.com/wangguibao)
 * @brief Generate all permutations for a given string
 * Example:
 *
 * input:
 * abc
 *
 * output:
 * abc
 * acb
 * bac
 * bca
 * cab
 * cba
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void permutation(char *str, int begin, int len)
{
    if (len == 0) {
        printf("%s\n", str);
        return;
    }

    int i = 0;
    for (; i < len; ++i) {
        char tmp = str[begin];
        str[begin] = str[begin + i];
        str[begin + i] = tmp;

        permutation(str, begin + 1, len - 1);

        tmp = str[begin];
        str[begin] = str[begin + i];
        str[begin + i] = tmp;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2) { 
        printf("Usage: ./permutation STRING\n");
        return 0;
    }

    char *str = (char *)malloc(strlen(argv[1]) + 1);
    strncpy(str, argv[1], strlen(argv[1]));

    permutation(str, 0, strlen(str));

    return 0;
}
