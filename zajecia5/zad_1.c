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

void add_first(node_t **head, int val) {
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

int main() {
    node_t *test_list = (node_t *) malloc(sizeof(node_t));
    test_list->val = 2;
    test_list->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->val = 3;
    test_list->next->next = NULL;

    add_first(&test_list, 1);
    print_list(test_list);

    }
    
