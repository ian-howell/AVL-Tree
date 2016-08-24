#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int max(int a, int b) { return (a > b) ? a : b; }

struct node *create_node(int x);
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

int main()
{
    struct node *my_tree = NULL;

    srand(time(NULL));
    /* srand(0); */

    int i = 0;
    for (i = 0; i < 20; i++)
    {
        int rand_num = rand() % 1000;
        avl_insert(&my_tree, rand_num);
        /* print_tree(my_tree); */
        /* printf("\n"); */
    }

    print_tree(my_tree);
    printf("\n");

    avl_delete(&my_tree, 690);
    avl_delete(&my_tree, 763);

    print_tree(my_tree);
    printf("\n");

    /* toDot(my_tree); */
    delete_tree(&my_tree);
    my_tree = NULL;

    return 0;

}

struct node *create_node(int x)
{
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = x;
    new_node->height = 0;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void delete_tree(struct node **root)
{
    if (*root == NULL)
    {
        return;
    }

    if ((*root)->left != NULL)
    {
        delete_tree(&(*root)->left);
    }

    if ((*root)->right != NULL)
    {
        delete_tree(&(*root)->right);
    }

    free(*root);
    *root = NULL;

    return;
}

int get_height(struct node *root)
{
    if (root == NULL)
        return -1;
    else
        return root->height;
}

int get_max(struct node *root)
{
    if (root->right == NULL)
        return root->data;
    else
        return get_max(root->right);
}

int get_min(struct node *root)
{
    if (root == NULL)
        return root->data;
    else
        return get_min(root->left);
}

void left_rotate(struct node **root)
{
    struct node *x = *root;
    struct node *y = x->right;
    struct node *t = y->left;

    x->right = t;
    y->left = x;

    x->height = 1 + max(get_height(x->left), get_height(x->right));
    y->height = 1 + max(get_height(y->left), get_height(y->right));

    *root = y;
}

void right_rotate(struct node **root)
{
    struct node *x = *root;
    struct node *y = x->left;
    struct node *t = y->right;

    x->left = t;
    y->right = x;

    x->height = 1 + max(get_height(x->left), get_height(x->right));
    y->height = 1 + max(get_height(y->left), get_height(y->right));

    *root = y;
}

void balance(struct node **root, int x)
{
    int bal = get_height((*root)->left) - get_height((*root)->right);
    if (bal > 1)
    {
        if (x > (*root)->left->data)
            left_rotate(&((*root)->left));
        right_rotate(root);
    }
    else if (bal < -1)
    {
        if (x < (*root)->right->data)
            right_rotate(&((*root)->right));
        left_rotate(root);
    }

    return;
}

void avl_insert(struct node **root, int x)
{
    if (*root == NULL)
    {
        *root = create_node(x);
        return;
    }

    if (x < (*root)->data)
        avl_insert((&(*root)->left), x);
    else
        avl_insert(&((*root)->right), x);

    int left_height = get_height((*root)->left);
    int right_height = get_height((*root)->right);

    (*root)->height = 1 + max(left_height, right_height);

    balance(root, x);

    return;
}

void avl_delete(struct node **root, int x)
{
    if (*root == NULL)
        return;

    if (x == (*root)->data)
    {
        if ((*root)->left == NULL && (*root)->right == NULL)
        {
            /* This node has no children */
            free(*root);
            *root = NULL;
        }
        else if ((*root)->left != NULL && (*root)->right != NULL)
        {
            /* This node has 2 children */
            (*root)->data = get_max((*root)->left);
            avl_delete(&(*root)->left, (*root)->data);
        }
        else
        {
            /* This node has exactly one child */
            struct node *child = (*root)->left;
            if (child == NULL)
                child = (*root)->right;
            free(*root);
            *root = child;
        }

        return;
    }
    else if (x < (*root)->data)
    {
        avl_delete(&(*root)->left, x);
    }
    else
    {
        avl_delete(&(*root)->right, x);
    }

    int left_height = get_height((*root)->left);
    int right_height = get_height((*root)->right);

    (*root)->height = 1 + max(left_height, right_height);

    balance(root, x);

    return;
}

void print_tree(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    print_tree(root->left);
    printf("%d ", root->data);
    print_tree(root->right);
}

void toDot(struct node *root)
{
    printf("digraph tree {\n");
    r_toDot(root);
    printf("}\n");
    return;
}

void r_toDot(struct node *root)
{
    static int nullCount = 0;

    printf("\t%ld [label=\"%d\"];\n", (long)root, root->data);

    if (root->left != NULL)
    {
        printf("\t%ld -> %ld;\n", (long)root, (long)root->left);
        r_toDot(root->left);
    }
    else
    {
        printf("\tnull%d [shape=point];\n", nullCount);
        printf("\t%ld -> null%d;\n", (long)root, nullCount);
        nullCount++;
    }

    if (root->right != NULL)
    {
        printf("\t%ld -> %ld;\n", (long)root, (long)root->right);
        r_toDot(root->right);
    }
    else
    {
        printf("\tnull%d [shape=point];\n", nullCount);
        printf("\t%ld -> null%d;\n", (long)root, nullCount);
        nullCount++;
    }
}
