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

void remove_by_value(node_t **head, int value) {
    node_t *node_itr = *head;
    node_t *prev_node = *head;

    if (node_itr != NULL && node_itr->val == value) {
        *head = node_itr->next;
        free(node_itr);
        return;
    }
    while (node_itr != NULL && node_itr->val != value) {
        prev_node= node_itr;
        node_itr= node_itr->next;
    }
    if (node_itr == NULL)
        return;
    prev_node->next = node_itr->next;
    free(node_itr);
}

int main() {
    node_t * test_list = (node_t *) malloc(sizeof(node_t));
    test_list->val = 2;
    test_list->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->val = 1;
    test_list->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->val = 2;
    test_list->next->next->next = NULL;
    
    remove_by_value(&test_list, 2);
    print_list(test_list);
}

