#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "avltree.h"

int main()
{
    struct node *my_tree = NULL;
    int i;

    /* srand(time(NULL)); */
    srand(0);

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
