#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
#include "../includes/node.h"
#include "../includes/stack.h"

void enqueue(stack *s1, stack *s2);
int queue_pop(stack *s1, stack *s2);

int main(){

        int test[] = {1, 2, 3, 4, 5};
        int test2[] = {-1, 10, 32, 44, 3};

        stack *s = malloc(sizeof(stack));      
        s->head = NULL;
        stack *s2 = malloc(sizeof(stack));
        s2->head = NULL;

        for(int i = 0; i < 5; i++) {
            push(s, test[i]);
        }

        for(int i = 0; i < 5; i++) {
                assert(test[i] == queue_pop(s, s2));
        }
   
        printf("1st test ok\n\r");

        for(int i = 0; i < 5; i++) {
            push(s, test2[i]);
        }

        for(int i = 0; i < 5; i++) {
                assert(test2[i] == queue_pop(s, s2));
        }
   
        printf("2nd test ok\n\r");

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
