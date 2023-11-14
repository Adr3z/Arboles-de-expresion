#include "stack.h"


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

void free_stack(stack_t *s)
{
    while (!isEmpty(s)) {
        node_tree_t *tmp = pop(s);
        free(tmp);
    }
}
