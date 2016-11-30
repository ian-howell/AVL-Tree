#ifndef NODE_H
#define NODE_H

typedef struct Node Node;
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};

Node *create_node(int x);

#endif
