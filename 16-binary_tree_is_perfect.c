#include <stddef.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_l, height_r;

    if (!tree)
        return (0);

    height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
    height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;

    return (height_l > height_r ? height_l : height_r);
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, otherwise 0. Return 0 if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    size_t height, size, max_size;

    if (!tree)
        return (0);

    height = binary_tree_height(tree);
    size = binary_tree_size(tree);
    max_size = (1 << (height + 1)) - 1;

    return (size == max_size);
}
