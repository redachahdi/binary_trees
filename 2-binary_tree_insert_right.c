#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * binary_tree_insert_right - is the insert in the right child of tree
 *
 * @parent: is the tree node
 * @value: is the value to insert
 *
 * Return: new node or NULL on fail
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *r_new_node;

	if (parent == NULL)
		return (NULL);
	r_new_node = binary_tree_node(parent, value);
	if (r_new_node == NULL)
		return (NULL);
	r_new_node->right = parent->right;
	if (r_new_node->right != NULL)
	{
		r_new_node->right->parent = r_new_node;
	}
	parent->right = r_new_node;
	return (r_new_node);
}
