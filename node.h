#ifndef NODE_H
#define NODE_H
struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

struct node *create_node(int x);

#endif
