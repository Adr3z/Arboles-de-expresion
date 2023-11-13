#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

/*
Códigos ASCII
+ 43
- 45
* 42
/ 47
*/

typedef struct node_tree node_tree_t;

struct node_tree{
    node_tree *right;
    node_tree *left;
    int clave;
}

typedef struct{
    node_tree_t *top;
    int size;
}stack_t;


//creates a node
node_tree_t* create_node( int value );

//stack functions
void initialize( stack_t *s);
void push(stack_t *s, node_tree_t *node);
node_tree_t* pop(stack_t *s);

//Main functions
node_tree_t *build_tree(char *);
void print_tree(node_tree_t *);
void evaluate_tree(node_tree_t *);

#endif
