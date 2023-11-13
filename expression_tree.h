#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

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

//creates a node
node_tree_t *create_node( int value );

//return ascii
int ascii(char op);

//free tree
void free_tree(node_tree_t *root);

//free all
void free_all(node_tree_t *root, stack_t *s);

//stack functions
void initialize( stack_t *s );
int isEmpty(stack_t *stack);
void push(stack_t *s, node_tree_t *node);
node_tree_t *pop(stack_t *s);
void free_stack(stack_t *s);

//Main functions
node_tree_t *build_tree(char *);
void print_tree(node_tree_t *);
void evaluate_tree(node_tree_t *);

#endif
