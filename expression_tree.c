#include <stdio.h>
#include "expression_tree.h"

node_tree_t* create_node( int value )
{
    node_tree_t* new = (node_tree_t*)malloc(sizeof(node_tree_t));
    new->value = value;
    new->left = NULL;
    new->right = NULL;
}

int ascii(char op)
{
    switch(op){
        case '+':
            return 43;
            break;
        case '-':
            return 45;
            break;
        case'*':
            return 42;
            break;
        case'/':
            return 47;
            break;
    }
}

void initialize(stack_t *s)
{
    s->size = 0;
    s->top = NULL;
}

void push(stack_t *s, node_tree_t *node)
{
    stack_node_t* new = (stack_node_t*)malloc(sizeof(stack_node_t));
    new->node = node;
    new->next = s->top;
    s->top = new;
}

node_tree_t* pop(stack_t *s)
{
    if(s->size == 0){
        return NULL;
    }

    stack_node_t *tmp = s->top;
    node_tree_t *node = tmp->node;

    s->top = tmp->next;
    free(tmp);

    return node;
}


//Main functions
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
