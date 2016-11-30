#include <stdlib.h>

#include "node.h"

Node *create_node(int x)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->data = x;
    new_node->height = 0;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}
