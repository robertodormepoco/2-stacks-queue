#ifndef __STACK
#define __STACK

#include<stdlib.h>
#include "../includes/node.h"
#include<assert.h>

typedef struct stack {
    struct node *head;
} stack;

void push(stack *s, int el);
int pop(stack *s);

#endif
