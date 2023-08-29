#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap to convert
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
    int *sorted_array;
    size_t array_size = binary_tree_size(heap);

    if (!heap || !size)
        return (NULL);

    sorted_array = malloc(sizeof(int) * array_size);
    if (!sorted_array)
        return (NULL);

    for (*size = 0; *size < array_size; (*size)++)
    {
        sorted_array[*size] = heap->n;
        heap_extract(&heap);
    }

    return (sorted_array);
}
