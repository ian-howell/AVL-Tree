#include <stdlib.h>

#include "node.h"

struct node *create_node(int x)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = x;
    new_node->height = 0;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
