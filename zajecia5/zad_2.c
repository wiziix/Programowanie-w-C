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

int pop(node_t **head) {
    int retval = -1;
    node_t * next_node = NULL;

    if (*head == NULL) {
        return -1;
    }

    next_node = (*head)->next;
    retval = (*head)->val;
    free(*head);
    *head = next_node;

    return retval;
}

int main() {
    node_t *test_list = (node_t *) malloc(sizeof(node_t));
    test_list->val = 2;
    test_list->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->val = 3;
    test_list->next->next = NULL;

    pop(&test_list);
    print_list(test_list);


    }

