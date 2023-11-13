#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

typedef struct node_tree node_tree_t;

node_tree_t *build_tree(char *);
void print_tree(node_tree_t *);
void evaluate_tree(node_tree_t *);

#endif
