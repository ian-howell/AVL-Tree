#ifndef AVLTREE_H
#define AVLTREE_H

#include "node.h"

void delete_tree(struct node **old_tree);

int get_height(struct node *root);
int get_max(struct node *root);
int get_min(struct node *root);

void left_rotate(struct node **root);
void right_rotate(struct node **root);
void balance(struct node **root, int x);

void avl_insert(struct node **root, int x);
void avl_delete(struct node **root, int x);

void print_tree(struct node *root);

void toDot(struct node *root);
void r_toDot(struct node *root);

#endif
