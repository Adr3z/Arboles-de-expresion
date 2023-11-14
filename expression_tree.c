#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
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

int tree_height(node_tree_t *root)
{
    if(root == NULL){
        return -1;
    }else{
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);
        if(left_height > right_height){
            return left_height + 1;
        }else{
            return right_height + 1;
        }
    }
}

void print_aux(node_tree_t *root, int depth)
{
    if(root != NULL){
        print_aux(root->left, depth + 1 );

        for( int i = 0; i < depth; i++){
            printf("       ");
        }
        if(root->value == '*' || root->value == '/' || root->value == '+' || root->value == '-'){
            printf("[%c]\n", root->value);
        }else{
            printf("[%d]\n", root->value);
        }

        print_aux(root->right, depth + 1);
    }
}

int evaluate_aux(node_tree_t *root)
{
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return root->value;
    }
    int val_left = evaluate_aux(root->left);
    int val_right = evaluate_aux(root->right);
    switch(root->value){
        case '+':
            return val_left + val_right;
        case '-':
            return val_left - val_right;
        case '*':
            return val_left * val_right;
        case '/':
            return val_left/val_right;
    }
    return 0;
}

void free_tree(node_tree_t *root)
{
    if (root != NULL) {
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

void free_all(node_tree_t *root, stack_t *s)
{
    free_tree(root);
    free_stack(s);
}

//Main functions
node_tree_t *build_tree(char *postfix_expression, stack_t *s, int *valid)
{
    printf("The expression is %s\n", postfix_expression);

    char *current = postfix_expression;
    
    while( *current != '\0'){
        char c = *current;
        if(isdigit(c)){
            int value = c - '0';
            node_tree_t *node = create_node(value);
            push(s, node);
        }else if(c == '+' || c == '-' || c == '*' || c == '/') {
            if (s->top == NULL || s->top->next == NULL) {
                printf("Error: Expresión posfija inválida.\n");
                *valid = 0;
                break;
            }
            int value = ascii(c);

            node_tree_t *op_node = create_node(value);
            op_node->right = pop(s);
            op_node->left = pop(s);

            push(s, op_node);
        }
        current++;
    }
    node_tree_t *root = pop(s);
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
        print_aux(root_node, 0);
    }
}

void evaluate_tree(node_tree_t *root_node)
{
    if (root_node == NULL)  {
        printf("You must build the tree!\n");
    }
    else {
        int result = evaluate_aux(root_node);
        printf("---------------------------------\n");
        printf("The result of the evaluation is: %d\n", result);
    }
}
