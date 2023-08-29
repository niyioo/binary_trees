#include "binary_trees.h"

/**
 * binary_tree_is_complete - Check if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int size = binary_tree_size(tree);
	return is_complete_recursive(tree, 0, size);
}
