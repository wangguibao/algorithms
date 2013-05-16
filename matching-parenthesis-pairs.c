/*
 * matching-parenthesis-pairs.c
 * Print out all valid parenthesis pair sequences
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_PAIRS   16

typedef enum _PARENTHESIS {                     /* Parenthesis type */
    NONE,
    LEFT,
    RIGHT
} PARENTHESIS;

int n;
PARENTHESIS stack[MAX_PAIRS * 2 + 1] = {NONE, };/* Simulate parenthesis stack */
int ind;                                        /* Current stack location */

/**
 * print_stack
 * Prints out the stack content
 */
void print_stack()
{
    int i;

    for (i = 1; i <= n * 2; i++) {
        if (stack[i] == LEFT) {
            printf("(");
        }
        else if (stack[i] == RIGHT) {
            printf(")");
        }
        else {
            printf("ERROR!!!!\n");
            exit(-1);
        }
    }

    printf("\n");
}

/**
 * matching_parenthesis_pairs
 *
 * Generate matching parenthesis pair sequences in a simulated stack.
 * Initially call matching_parenthesis_pairs(0, 0)
 *
 * @param left_in_stack Current number of left parentheses in stack
 * @param right_in_stack Current number of right parentheses in stack
 */
void matching_parenthesis_pairs(int left_in_stack, int right_in_stack)
{
    if (left_in_stack < right_in_stack) {
        return;
    }

    if (ind == n * 2 + 1)
    {
        print_stack();
        return;
    }

    if (left_in_stack < n) {
        stack[ind++] = LEFT;
        matching_parenthesis_pairs(left_in_stack + 1, right_in_stack);
        ind--;
    }
    if (right_in_stack < left_in_stack) {
        stack[ind++]= RIGHT;
        matching_parenthesis_pairs(left_in_stack, right_in_stack + 1);
        ind--;
    }
}

int main()
{
    printf("Number of parenthesis pairs (max %d): ", MAX_PAIRS);
    scanf("%d", &n);

    ind = 1;
    matching_parenthesis_pairs(0, 0);

    return 0;
}
