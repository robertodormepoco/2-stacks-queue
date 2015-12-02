#include "../includes/stack.h"

int pop(stack *s){
        assert(s->head != NULL);
        int val = s->head->val;
        node *n = s->head;
        s->head = s->head->next;
        free(n);
        return val;
}

void push(stack *s, int el){
    node *n = malloc(sizeof(node));
    n->val = el;
    n->next = s->head;
    s->head = n;
}
