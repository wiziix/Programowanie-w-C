#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;

void print_list(node_t * head) {
    node_t * current = head;

    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

node_t * remove_last(node_t *head) {
    if (head == NULL) {
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    node_t * second_last = head;
    while(second_last->next->next != NULL) {
        second_last = second_last->next;
    }

    free(second_last->next);

    second_last->next = NULL;

    return head;
}

int main() {
    node_t * test_list = (node_t *) malloc(sizeof(node_t));
    test_list->val = 1;
    test_list->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = NULL;

    remove_last(test_list);
    print_list(test_list);
    }

