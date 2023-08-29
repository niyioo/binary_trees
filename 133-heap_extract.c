#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    int extracted_value, last_value;
    heap_t *last_node, *current;
    size_t bits = 0;

    if (!root || !*root)
        return (0);

    extracted_value = (*root)->n;
    last_node = binary_tree_get_last(*root, &bits);
    last_value = last_node->n;

    if (last_node->parent)
    {
        if (last_node->parent->right)
            last_node->parent->right = NULL;
        else
            last_node->parent->left = NULL;
    }
    else
        *root = NULL;

    if (*root != last_node)
    {
        (*root)->n = last_value;
        heapify_down(*root);
    }

    free(last_node);
    return (extracted_value);
}
