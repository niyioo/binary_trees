#include "binary_trees.h"

/**
 * avl_rotate_left - Performs a left-rotation on an AVL tree
 * @y: Pointer to the root of the rotation
 * Return: Pointer to the new root after rotation
 */
avl_t *avl_rotate_left(avl_t *y)
{
    avl_t *x, *T2;

    x = y->right;
    T2 = x->left;

    x->left = y;
    y->right = T2;

    y->height = 1 + MAX(binary_tree_height(y->left), binary_tree_height(y->right));
    x->height = 1 + MAX(binary_tree_height(x->left), binary_tree_height(x->right));

    return (x);
}

/**
 * avl_rotate_right - Performs a right-rotation on an AVL tree
 * @x: Pointer to the root of the rotation
 * Return: Pointer to the new root after rotation
 */
avl_t *avl_rotate_right(avl_t *x)
{
    avl_t *y, *T2;

    y = x->left;
    T2 = y->right;

    y->right = x;
    x->left = T2;

    x->height = 1 + MAX(binary_tree_height(x->left), binary_tree_height(x->right));
    y->height = 1 + MAX(binary_tree_height(y->left), binary_tree_height(y->right));

    return (y);
}

/**
 * avl_insert - Inserts a value in an AVL tree
 * @tree: Double pointer to the root node of the AVL tree
 * @value: Value to insert
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
    avl_t *new_node;

    if (!tree)
	    return (NULL);

    if (*tree == NULL)
    {
	    new_node = binary_tree_node(NULL, value);
	    if (!new_node)
		    return (NULL);
	    *tree = new_node;
	    return (new_node);
    }

    if (value < (*tree)->n)
    {
	    (*tree)->left = avl_insert(&(*tree)->left, value);
    }
    else if (value > (*tree)->n)
    {
	    (*tree)->right = avl_insert(&(*tree)->right, value);
    }
    else
    {
	    return (NULL);
    }

    (*tree)->height = 1 + MAX(binary_tree_height((*tree)->left), binary_tree_height((*tree)->right));

    int balance = binary_tree_balance(*tree);

    if (balance > 1 && value < (*tree)->left->n)
	    return (avl_rotate_right(*tree));

    if (balance < -1 && value > (*tree)->right->n)
	    return (avl_rotate_left(*tree));

    if (balance > 1 && value > (*tree)->left->n)
    {
	    (*tree)->left = avl_rotate_left((*tree)->left);
	return (avl_rotate_right(*tree));
    }

    if (balance < -1 && value < (*tree)->right->n)
    {
	    (*tree)->right = avl_rotate_right((*tree)->right);
	    return (avl_rotate_left(*tree));
    }

    return (*tree);
}
