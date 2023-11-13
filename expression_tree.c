#include <stdio.h>
#include "expression_tree.h"

node_tree_t *build_tree(char *postfix_expression)
{
    printf("The expression is %s\n", postfix_expression);
    return NULL;
}

void print_tree(node_tree_t *root_node)
{
    if (root_node == NULL)  {
        printf("You must build the tree!\n");
    }
    else {
        printf("The contents of the tree is\n");
        printf("---------------------------\n");
    }
}

void evaluate_tree(node_tree_t *root_node)
{
    if (root_node == NULL)  {
        printf("You must build the tree!\n");
    }
    else {
        printf("---------------------------------\n");
        printf("The result of the evaluation is:\n");
    }
}
