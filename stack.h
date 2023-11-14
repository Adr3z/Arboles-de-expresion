#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stddef.h>
#include <stdlib.h>

/*
Códigos ASCII
+ 43
- 45
* 42
/ 47
*/

typedef struct node_tree node_tree_t;
typedef struct stack stack_t;
typedef struct stack_node stack_node_t;

struct node_tree{
    node_tree_t *right;
    node_tree_t *left;
    int value;
};

struct stack_node{
    node_tree_t *node;
    stack_node_t *next;
};

struct stack{
    stack_node_t *top;
};

//initialize stack
void initialize( stack_t *s );

//check if the stack is empty
int isEmpty(stack_t *stack);

//push an element
void push(stack_t *s, node_tree_t *node);

//pop an element
node_tree_t *pop(stack_t *s);

//free stack
void free_stack(stack_t *s);

#endif
