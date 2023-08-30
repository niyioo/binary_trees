#include <stdlib.h>
#include "binary_trees.h"

/**
 * heapify - Orders the heap
 * @new: Pointer to the new node
 *
 * Return: Pointer to the ordered heap
 */
heap_t *heapify(heap_t *new)
{
    int temp;
    heap_t *current = new;

    while (current->parent && current->n > current->parent->n)
    {
	    temp = current->n;
	    current->n = current->parent->n;
	    current->parent->n = temp;
	    current = current->parent;
    }
    return (current);
}

/**
 * heap_insert - Inserts a value in a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the created node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new, *current;

    if (!root)
	    return (NULL);

    new = binary_tree_node(NULL, value);
    if (!new)
	    return (NULL);

    if (!*root)
    {
	    *root = new;
	    return (new);
    }

    current = *root;
    while (current->left && current->right)
    {
	    if (binary_tree_balance(current->left) >= 0)
		    current = current->left;
	    else
		    current = current->right;
    }

    if (!current->left)
	    current->left = new;
    else
	    current->right = new;

    new->parent = current;
    return (heapify(new));
}
