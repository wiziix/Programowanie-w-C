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

void remove_by_index(node_t **head, int index) {
    if(head == NULL) {
        return;
    }

    node_t *temp = *head;

    if(index == 0) {
        *head = temp->next;
        free(temp);
        return;
    }

    for(int i = 0; i < (index - 1); i++) {
        temp = temp->next;
    }

    if(temp == NULL || temp->next == NULL) {
        return;
    }

    node_t *next1 = temp->next->next;

    free(temp->next);
    temp->next = next1;
}

int main() {
    node_t * test_list = (node_t *) malloc(sizeof(node_t));
    test_list->val = 1;
    test_list->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->val = 2;
    test_list->next->next = (node_t *) malloc(sizeof(node_t));
    test_list->next->next->val = 3;
    test_list->next->next->next = NULL;

    remove_by_index(&test_list, 1);
    print_list(test_list);
}

