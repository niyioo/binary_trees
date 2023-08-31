#include <stddef.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_node - Create a new BST node.
 * @parent: Pointer to the parent node.
 * @value: Value to store in the node.
 *
 * Return: Pointer to the newly created node.
 */
bst_t *bst_node(bst_t *parent, int value)
{
	bst_t *new_node = malloc(sizeof(bst_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}

/**
 * bst_insert - Insert a value into a Binary Search Tree.
 * @tree: Double pointer to the root node of the tree.
 * @value: Value to insert.
 *
 * Return: Pointer to the newly created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = bst_node(NULL, value);
		return (*tree);
	}

	if (value < (*tree)->n)
	{
		if ((*tree)->left == NULL)
		{
			(*tree)->left = bst_node(*tree, value);
			return ((*tree)->left);
		}
		return (bst_insert(&((*tree)->left), value));
	}

	if (value > (*tree)->n)
	{
		if ((*tree)->right == NULL)
		{
			(*tree)->right = bst_node(*tree, value);
			return ((*tree)->right);
		}
		return (bst_insert(&((*tree)->right), value));
	}

	return (NULL);
}

