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

node_t *insert_by_index(node_t *head, int position, int value) {
    node_t *new = (node_t *) malloc(sizeof(node_t));
    new->val = value;
    new ->next = NULL;

    // If the position is 0, insert the new node at the beginning of the list
    if (position == 0) {
        new->next = head;
        head = new;
    }
        // Otherwise, traverse the list to the position before the insertion point
    else {
        node_t* current = head;
        for (int i = 0; i < position - 1; i++) {
            if (current == NULL) {
                // If the position is out of range, return the original list
                return head;
            }
            current = current->next;
        }
        // Insert the new node after the last node that was traversed
        new->next = current->next;
        current->next = new;
    }

    // Return the updated list
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

    test_list = insert_by_index(test_list, 0, 120);
    print_list(test_list);
}
