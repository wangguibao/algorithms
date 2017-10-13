#include <stdio.h>
#include <string.h>

#define LINE_LIMIT  16      /* Max input element length */
#define ELEM_LIMIT  128     /* Max element count */
typedef struct tag_STACK
{
    float elem[ELEM_LIMIT];
    int top;
} stack;

void stack_init(stack *s)
{
    int i = 0;

    s->top = 0;
    for (i = 0; i < ELEM_LIMIT; i++) {
        s->elem[i] = 0;
    }
}

int stack_empty(stack *s)
{
    if (s->top == 0) {
        return 1;
    }
    return 0;
}

float stack_push(stack *s, float elem)
{
    if (s->top == ELEM_LIMIT) {
        printf("Stack overflow!\n");
        return -1;
    }
    s->elem[s->top] = elem;
    s->top++;
    return 0;
}

float stack_pop(stack *s)
{
    if (s->top == ELEM_LIMIT) {
        printf("Stack underflow!\n");
        return -1;
    }
    s->top--;
    return s->elem[s->top];
}

float stack_top(stack *s)
{
    if (s->top == ELEM_LIMIT) {
        return -1;
    }
    return s->elem[s->top - 1];
}

/*
 * Returns relative priority of two operators
 * 1) '+', '-' are lower than '*' and '/'
 * 2) In each group, '+' and '-', or '*' and '/', they are equal
 * return value:
 *    0: op1 is equal to op2
 *    1: op1 is higher than op2
 *    -1 op1 is lower than op2
 */
int op_pri(char op1, char op2)
{
    switch (op1) {
        case '+':
        case '-':
            switch (op2) {
                case '+':
                case '-':
                    return 0;
                case '*':
                case '/':
                    return -1;
                default:
                    return 0;
            }
        case '*':
        case '/':
            switch (op2) {
                case '+':
                case '-':
                    return 1;
                case '*':
                case '/':
                    return 0;
                default:
                    return 0;
            }
        default:
            return 0;
    }
}

float cal(float oprand1, char op, float oprand2)
{
    float result = 0;

    switch (op) {
       case '+':
           result = oprand1 + oprand2;
           break;
       case '-':
           result = oprand1 - oprand2;
           break;
        case '*':
           result = oprand1 * oprand2;
           break;
        case '/':
            result = oprand1 / oprand2;
            break;
        default:
            break;
    }
    return result;
}
int main(int argc, char *argv[])
{
    char  buf[LINE_LIMIT];
    char  *p = buf;
    float oprand = 0;
    float oprand1 = 0;
    float oprand2 = 0;
    char  op     = '\0';
    int   priority;
    stack s_op;
    stack s_oprand;
    float result = 0.0;

    buf[LINE_LIMIT - 1] ='\0';
    stack_init(&s_op);      /* Init stack space */
    stack_init(&s_oprand);

    for (;;) {
        scanf("%s", buf);     /* Read in input string */
        sscanf(p, "%f", &oprand);
        stack_push(&s_oprand, oprand);

        scanf("%s", buf);
        sscanf(p, "%c", &op);
        if (op == '=') {
            oprand1 = stack_pop(&s_oprand);
            oprand2 = stack_pop(&s_oprand);

            oprand2 = cal(oprand2, stack_pop(&s_op), oprand1);
            stack_push(&s_oprand, oprand2);
            break;
        }
        else if (op != '+' && op != '-' && op != '*' && op != '/') {
            printf("Input format error at %d\n", p - buf);
            return -1;
        }
        else {
            if (stack_empty(&s_op)) {
                stack_push(&s_op, op);
                continue;
            }
            priority = op_pri(stack_top(&s_op), op);
            if (priority != -1) {
                oprand1 = stack_pop(&s_oprand);
                oprand2 = stack_pop(&s_oprand);

                oprand2 = cal(oprand2, stack_pop(&s_op), oprand1);
                stack_push(&s_oprand, oprand2);
            }
            stack_push(&s_op, op);
        }
    }
    /* Remaining parts handling */
    while (!stack_empty(&s_op)) {
        oprand1 = stack_pop(&s_oprand);
        oprand2 = stack_pop(&s_oprand);
        oprand2 = cal(oprand2, stack_pop(&s_op), oprand1);
        stack_push(&s_oprand, oprand2);
    }
    result = stack_pop(&s_oprand);
    result += 0.5;
    printf("%d\n", (int)result);
    return 0;
}

