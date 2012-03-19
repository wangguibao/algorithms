/*
 * array_rhr.c - Right shift all elements in an array, using 1 swap element
 * space. Also must keep the complexity O(n).
 *
 * This algorithm is copied from the Internet,
 * http://blog.sina.com.cn/s/blog_3ee549da01009msh.html
 * Many thanks to the author.
 */

#include <stdio.h>

#define ARRAY_LEN   6

void Reverse(int *arr, int a, int b)
{
    int temp=0;

    while(a < b) {
        temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
        a++;
        b--;
    }
}

void RightShift(int *arr, int n, int k)
{
    k %= n;
    Reverse(arr, 0, n-k-1);
    Reverse(arr, n-k, n-1);
    Reverse(arr, 0, n-1);
}

int main(int argc, char *argv[])
{
    int test[ARRAY_LEN] = {0, 1, 2, 3, 4, 5};
    int i = 0;
    
    RightShift(test, 6, 2);
    
    for (i = 0; i < ARRAY_LEN; i++) {
        printf("%d ", test[i]);
    }
    printf("\n");
    exit(0);
}

