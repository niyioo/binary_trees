#include "binary_trees.h"

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    (return) is_bst_recursive(tree, NULL, NULL);
}

/**
 * is_bst_recursive - Recursive helper function to check if a tree is a valid BST.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Pointer to the minimum value the current node can have.
 * @max: Pointer to the maximum value the current node can have.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */
int is_bst_recursive(const binary_tree_t *tree, const int *min, const int *max)
{
    if (!tree)
	    return (1);

    if ((min && tree->n <= *min) || (max && tree->n >= *max))
	    return (0);

    return (is_bst_recursive(tree->left, min, &tree->n) &&
		    is_bst_recursive(tree->right, &tree->n, max));
}
