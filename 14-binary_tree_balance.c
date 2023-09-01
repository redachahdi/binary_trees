#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * binary_tree_height_1 - is the measures the hight of the tree
 *
 * @tree: iss the pointer to the root node of the tree
 *
 * Return: is the 0 if tree is NULL else the hight
 */
int binary_tree_height_1(const binary_tree_t *tree)
{
	int r_h_left;
	int r_h_right;

	if (tree == NULL)
		return (0);
	r_h_left = binary_tree_height_1(tree->left);
	r_h_right = binary_tree_height_1(tree->right);
	if (r_h_left >= r_h_right)
		return (r_h_left + 1);

	return (r_h_right + 1);

}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: is the  pointer to the root node of the tree to measure the balance
 *
 * Return: is the 0 or balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left;
	int right;

	if (tree == NULL)
		return (0);

	left = binary_tree_height_1(tree->left);
	right = binary_tree_height_1(tree->right);
	return (left - right);
}
