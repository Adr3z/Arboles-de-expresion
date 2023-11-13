#include <stdio.h>
#include <ctype.h>
#include "expression_tree.h"

node_tree_t *create_node( int value )
{
    node_tree_t *new = (node_tree_t*)malloc(sizeof(node_tree_t));
    new->value = value;
    new->left = new->right = NULL;
    return new;
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
    return 0;
}

void initialize(stack_t *s)
{
    s->top = NULL;
}

int isEmpty(stack_t *stack) 
{
    return stack->top == NULL;
}

void push(stack_t *s, node_tree_t *node)
{
    stack_node_t* new = (stack_node_t*)malloc(sizeof(stack_node_t));
    new->node = node;
    new->next = s->top;
    s->top = new;
}

node_tree_t *pop(stack_t *s)
{
    if(isEmpty(s)){
        return NULL;
    }

    stack_node_t *tmp = s->top;
    node_tree_t *node = tmp->node;

    s->top = tmp->next;
    free(tmp);

    return node;
}

void free_tree(node_tree_t *root)
{
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

void free_stack(stack_t *s)
{
    while (!isEmpty(s)) {
        node_tree_t *tmp = pop(s);
        free(tmp);
    }
}

void free_all(node_tree_t *root, stack_t *s)
{
    free_tree(root);
    free_stack(s);
}

//Main functions
node_tree_t *build_tree(char *postfix_expression)
{
    printf("The expression is %s\n", postfix_expression);

    stack_t s;
    initialize(&s);

    char *current = postfix_expression;

    while( *current != '\0'){
        char c = *current;
        if(isdigit(c)){
            int value = c - '0';
            node_tree_t *node = create_node(value);
            push(&s, node);
        }else if(c == '+' || c == '-' || c == '*' || c == '/') {
            int value = ascii(c);

            node_tree_t *op_node = create_node(value);
            op_node->right = pop(&s);
            op_node->left = pop(&s);

            push(&s, op_node);
        }
        current++;
    }
    node_tree_t *root = pop(&s);
    free_all(root, &s);
    return root;
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
