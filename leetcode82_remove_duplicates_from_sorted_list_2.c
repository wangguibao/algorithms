/**
 * @file leetcode82_remove_duplicates_from_ascending_order_list_2.c
 * @author wangguibao(https://github.com/wangguibao)
 * @date 2021/12/07 15:59:39
 * @brief Removing all duplicates from a sorted list
 *
 **/
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAL (200 + 1)

#define MAX_ELE 100

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    int count[MAX_VAL];

    struct ListNode new_head;
    new_head.next = head;
    struct ListNode* p = new_head.next;
    struct ListNode* q = &new_head;

    for (int i = 0; i < MAX_VAL; ++i) {
        count[i] = 0;
    }

    while (p) {
        count[p->val + 100]++;
        p = p->next;
    }

    p = new_head.next;
    while (p) {
        if (count[p->val + 100] > 1) {
            q->next = p->next;
            free(p);
            p = q->next;
        } else {
            q = p;
            p = p->next;
        }
    }
    return new_head.next;
}

/*
 * constructList
 * @brief construct a list from a given integer array
 *
 * @input a input array
 * @input n input array size
 *
 * @return constructed list
 */
struct ListNode* constructList(const int* a, int n) {
    struct ListNode* head = NULL;
    struct ListNode* p = NULL;

    for (int i = 0; i < n; ++i) {
        struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
        node->val = a[i];
        node->next = NULL;

        if (head == NULL) {
            head = node;
            p = node;
        } else{
            p->next = node;
            p = p->next;
        }
    }

    return head;
}

void printList(struct ListNode* list) {
    struct ListNode* p = list;

    while (p) {
        printf("%d ", p->val);
        p = p->next;
    }

    printf("\n");
}

int main() {
    int n;
    int a[MAX_ELE];
    struct ListNode* list = NULL;

    while (1) {
        printf("Number of elements: ");
        int nscan = scanf("%d", &n);
        if (nscan < 1 || n <= 0) {
            return 0;
        }

        printf("%d integers: ", n);
        memset(a, 0, MAX_ELE * sizeof(int));
        int i = 0;
        for (; i < n; ++i) {
            nscan = scanf("%d", &a[i]);
            if (nscan != 1) {
                printf("Input invalid");
                return -1;
            }
        }

        list = constructList(a, n);
        printf("Before removing duplicates: \n");
        printList(list);

        list = deleteDuplicates(list);
        printf("After removing duplicates: \n");
        printList(list);

        list = NULL;
        printf("\n");
    }
}

/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
