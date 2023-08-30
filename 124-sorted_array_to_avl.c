#include "binary_trees.h"

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to the first element of the sorted array
 * @size: The number of elements in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (size == 0)
	    return (NULL);

    size_t mid = size / 2;
    avl_t *root = avl_create_node(array[mid]);

    if (!root)
	    return (NULL);

    root->left = sorted_array_to_avl(array, mid);
    root->right = sorted_array_to_avl(array + mid + 1, size - mid - 1);

    return (root);
}
