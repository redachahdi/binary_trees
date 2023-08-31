#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_t - is function Stores recursively
 * @tree: is the Pointer 
 * @r_offset: r_ is Offset to print
 * @r_depth: is the r_Depth of the node
 * @r_s: Buffer
 *
 * Return: is the length of printed tree
 */
static int r_print_t(const binary_tree_t *tree, int r_offset, int r_depth, char **r_s)
{
	char b[6];
	int r_width, left;
	int right, r_is_left, r_i;

	if (!tree)
		return (0);
	r_is_left = (tree->parent && tree->parent->left == tree);
	r_width = sprintf(b, "(%03d)", tree->n);
	left = r_print_t(tree->left, r_offset, r_depth + 1, r_s);
	right = r_print_t(tree->right, r_offset + left + r_width, r_depth + 1, r_s);
	for (r_i = 0; r_i < r_width; r_i++)
		r_s[r_depth][r_offset + left + r_i] = b[r_i];
	if (r_depth && r_is_left)
	{
		for (r_i = 0; r_i < r_width + right; r_i++)
			r_s[r_depth - 1][r_offset + left + r_width / 2 + r_i] = '-';
		r_s[r_depth - 1][r_offset + left + r_width / 2] = '.';
	}
	else if (r_depth && !r_is_left)
	{
		for (r_i = 0; r_i < left + r_width; r_i++)
			r_s[r_depth - 1][r_offset - r_width / 2 + r_i] = '-';
		r_s[r_depth - 1][r_offset + left + r_width / 2] = '.';
	}
	return (left + r_width + right);
}

/**
 * r_height - is the measures the height
 * @tree: is the Pointer to the node to measures the height
 *
 * Return: is the he height of the tree starting at @node
 */
static size_t _r_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	height_l = tree->left ? 1 + _r_height(tree->left) : 0;
	height_r = tree->right ? 1 + _r_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 * r_binary_tree_print - is the Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **r_s;
	size_t r_height, r_i, r_j;

	if (!tree)
		return;
	r_height = _r_height(tree);
	r_s = malloc(sizeof(*r_s) * (r_height + 1));
	if (!r_s)
		return;
	for (r_i = 0; r_i < r_height + 1; r_i++)
	{
		r_s[r_i] = malloc(sizeof(**r_s) * 255);
		if (!r_s[r_i])
			return;
		memset(r_s[r_i], 32, 255);
	}
	r_print_t(tree, 0, 0, r_s);
	for (r_i = 0; r_i < r_height + 1; r_i++)
	{
		for (r_j = 254; r_j > 1; --r_j)
		{
			if (r_s[r_i][r_j] != ' ')
				break;
			r_s[r_i][r_j] = '\0';
		}
		printf("%s\n", r_s[r_i]);
		free(r_s[r_i]);
	}
	free(r_s);
}
