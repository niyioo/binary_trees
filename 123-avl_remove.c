#include "binary_trees.h"

/**
 * avl_remove - Removes a node from an AVL tree
 * @root: Pointer to the root node of the tree for removing a node
 * @value: The value to remove in the tree
 * Return: Pointer to the new root node of the tree after removing the value
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (!root)
        return NULL;

    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        if (!root->left || !root->right)
        {
            avl_t *temp = root->left ? root->left : root->right;
            free(root);
            return temp;
        }

        avl_t *temp = avl_find_min(root->right);
        root->n = temp->n;
        root->right = avl_remove(root->right, temp->n);
    }

    root = avl_balance(root);
    return root;
}
