#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * binary_tree_depth - is the measures the depth of the 
 *
 * @tree: is the pointer to the root node 
 *
 * Return: is the 0 if tree is NULL else
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t r_depth = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent)
	{
		r_depth++;
		tree = tree->parent;
	}
	return (r_depth);

}
