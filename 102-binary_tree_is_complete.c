#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_is_complete - Check if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int size = binary_tree_size(tree);

	return (is_complete_recursive(tree, 0, size));
}

/**
 * binary_tree_size - Measure the size of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: Size of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * is_complete_recursive - Helper function to check
 * if a binary tree is complete.
 * @tree: Pointer to the current node.
 * @index: Current index of the node.
 * @size: Size of the entire tree.
 *
 * Return: 1 if the subtree is complete, 0 otherwise.
 */
int is_complete_recursive(const binary_tree_t *tree, int index, int size)
{
	if (tree == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete_recursive(tree->left, 2 * index + 1, size) &&
		is_complete_recursive(tree->right, 2 * index + 2, size));
}
