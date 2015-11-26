#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

typedef struct node {
        int val;
        struct node *next;
} node;

typedef struct stack {
        struct node *head;
} stack;

void enqueue(stack *s1, stack *s2);
void push(stack *s, int el);
int pop(stack *s);
int queue_pop(stack *s1, stack *s2);

int main(){

        int test[] = {1, 2, 3, 4, 5};

        stack *s = malloc(sizeof(stack));      
        s->head = NULL;
        stack *s2 = malloc(sizeof(stack));
        s2->head = NULL;

        push(s, 1);
        push(s, 2);
        push(s, 3);
        push(s, 4);


        printf("%d\n\r", queue_pop(s, s2));
        printf("%d\n\r", queue_pop(s, s2));
        printf("%d\n\r", queue_pop(s, s2));
        printf("%d\n\r", queue_pop(s, s2));

        return 0;
}

void enqueue(stack *s1, stack *s2){
        while(s1->head != NULL){
            push(s2, pop(s1)); 
        }
}

int queue_pop(stack *s1, stack *s2){
   if(s2->head == NULL){
           enqueue(s1, s2);
   }

   return pop(s2);
}

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
