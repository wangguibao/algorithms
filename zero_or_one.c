/*
 * zero_or_one: Hash a string into either 0 or 1 with equal chance.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*
 * half_hash
 * @brief hash a string into either 0 or 1
 *        Copied idea from bkdr hash: for mapping a string into 0 or 1, only small part
 *        of string is needed.
 *        Note the byte count 'count' and hash bucket size '1000' was picked arbitrarily
 */
int half_hash(char *str, int len)
{
    int i = 0;
    uint64_t v = 0;
    int count = 0;
    for (i = strlen(str) - 1; i >= 0; --i) {
        char a = str[i];

        v = (v * 131 + a) % 1000;
        ++count;
        if (count >= 4) {
            break;
        }
        //printf("%lu\n", v);
    }

    if (v > 499) {
        return 1;
    }
    else {
        return 0;
    }
}

/*
 * Test half_hash with a text file, each line ending with a newline
 */
int main(int argc, char *argv[])
{
    if (argc != 2) {
        return -1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return -1;
    }

    char buffer[64];
    int ret;
    int zero = 0;
    int one = 0;
    while (!feof(fp) && fgets(buffer, 64, fp) != NULL) {
        buffer[strlen(buffer) - 1] = '\0';
        printf("%s\n", buffer);
        ret = half_hash(buffer, strlen(buffer));
        if (ret == 0) {
            ++zero;
        }
        if (ret == 1) {
            ++one;
        }
    }        

    printf("zero = %d, one = %d\n", zero, one);
    return 0;
}
