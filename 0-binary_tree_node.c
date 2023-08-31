#include "binary_trees.h"

#include <stddef.h>
/**
 * binary_tree_node - function that create a binary tree node
 *
 * @parent: root node 
 * @value: is the value root note
 *
 * Return: binary tree
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t  *newtree;

	newtree = malloc(sizeof(binary_tree_t));
	if (newtree == NULL)
		return (NULL);
	newtree->parent = parent;
	newtree->n = value;
	newtree->right = NULL;
	newtree->left = NULL;
	return (newtree);
}
