#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * binary_tree_leaves - is the Counts the leaves in a binar
 *
 * @tree: is the  pointer to the root node of the tree to count the leaves
 *
 * Return: The number of leaves in the tree.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
        size_t r_leaves = 0;

        if (tree)
        {
                r_leaves += (!tree->left && !tree->right) ? 1 : 0;
                r_leaves += binary_tree_leaves(tree->left);
                r_leaves += binary_tree_leaves(tree->right);
        }
        return (r_leaves);
}
