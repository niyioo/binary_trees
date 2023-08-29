#include <stddef.h>
#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 *
 * Return: Pointer to the sibling node, or NULL in various cases
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node);

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node, or NULL in various cases
 */
{
    if (!node || !node->parent)
        return (NULL);

    if (node->parent->left == node)
        return (node->parent->right);

    return (node->parent->left);
}
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (!node || !node->parent)
        return (NULL);

    return (binary_tree_sibling(node->parent));
}
