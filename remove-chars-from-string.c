/**
 * remove-chars-from-string.c
 * Wang Guibao, 20130405
 * Ideas inspired from:
 * http://stackoverflow.com/a/8733511/1513460, by Fabio Cabral[http://stackoverflow.com/users/560070/fabio-cabral]
 * http://rosettacode.org/wiki/Strip_a_set_of_characters_from_a_string
 *
 * Function remove_char_from_string() removes a single char from string
 * Function remove_chars_from_string() removes a set of chars from string
 *
 * Appearantly both function operate inplace
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *str = "Almost every beginning C programmer independently rediscovers"
                    " the same mistake";
const char *charset = "cde";

/*
 * Remove a single character from a string
 */
char *remove_char_from_string(char *str, const char garbage)
{
    char *src;
    char *dst;

    for (src = dst = str; *src != '\0'; src++) {
        if (*src != garbage) {
            *dst = *src;
            dst++;
        }
    }
    *dst = '\0';

    return str;
}

/*
 * Remove a set of characters in serach from a string
 */
char *remove_chars_from_string(char *str, const char *search)
{
    int pattern[128] = {'\0'};
    char *src;
    char *dst;
    char *p;

    for (p = (char *)search; *p != '\0'; p++) {
        pattern[(int)*p] = 1;
    }

    for (src = dst = str; *src != '\0'; src++) {
        if (pattern[(int)*src] != 1) {
            *dst = *src;
            dst++;
        }
    }
    *dst = '\0';

    return str;
}

int main()
{
    char *buf = malloc(strlen(str) + 1);

    printf("Original: %s\n", str);
    /* Remove a single character from string */
    memset(buf, 0, strlen(str) + 1);
    strncpy(buf, str, strlen(str));
    remove_char_from_string(buf, 'e');
    printf("Remove single char (e): %s\n", buf);

    /* Remove a set of characters from string */
    memset(buf, 0, strlen(str) + 1);
    strncpy(buf, str, strlen(str));
    remove_chars_from_string(buf, charset);
    printf("Remove chars (%s): %s\n", charset, buf);

    return 0;
}
