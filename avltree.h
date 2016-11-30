#ifndef AVLTREE_H
#define AVLTREE_H

#include "node.h"

void delete_tree(Node **old_tree);

int get_height(Node *root);
int get_max(Node *root);
int get_min(Node *root);

void left_rotate(Node **root);
void right_rotate(Node **root);
void balance(Node **root, int x);

void avl_insert(Node **root, int x);
void avl_delete(Node **root, int x);

void print_tree(Node *root);

void toDot(Node *root);
void r_toDot(Node *root);

#endif
