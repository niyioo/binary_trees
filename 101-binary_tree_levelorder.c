#include <stddef.h>
#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverse a binary tree using level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node's value
 *
 * This function traverses the binary tree using level-order traversal,
 * calling the provided function for each node's value.
 * If tree or func is NULL, do nothing.
 */
void binary_tree_levelorder(const binary_tree_t *tree,
                            void (*func)(int))
{
    if (!tree || !func)
        return;

    binary_tree_t *queue[10000];
    int front = 0, rear = 0;

    queue[rear++] = (binary_tree_t *)tree;

    while (front < rear)
    {
        binary_tree_t *node = queue[front++];

        func(node->n);

        if (node->left)
            queue[rear++] = node->left;

        if (node->right)
            queue[rear++] = node->right;
    }
}
