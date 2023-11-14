#include <stdio.h>
#include "expression_tree.h"

int main(void)  {
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "rt", stdout);
    int n;
    char postfix_expression[80];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)    {
        stack_t s;
        initialize(&s);
        printf("\n--------------\nExpression #%d\n--------------\n", i);
        scanf("%s", postfix_expression);
        node_tree_t *root_node = build_tree(postfix_expression, &s);
        print_tree(root_node);
        evaluate_tree(root_node);
        free_all(root_node, &s);
    }
    return 0;
}


