#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <stdlib.h>

#include "stack.h"

//creates a node
node_tree_t *create_node( int value );

//return ascii
int ascii(char op);

//tree height
int tree_height(node_tree_t *root);

//aux function for impression
void print_aux(node_tree_t *root, int depth);

//aux function for evaluation
int evaluate_aux(node_tree_t *root);

//free tree
void free_tree(node_tree_t *root);

//free all
void free_all(node_tree_t *root, stack_t *s);

//Main functions
node_tree_t *build_tree(char *, stack_t *s);
void print_tree(node_tree_t *);
void evaluate_tree(node_tree_t *);

#endif
