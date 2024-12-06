#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

int _binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_balance -  measures the balance factor
 * of a binary tree
 * @tree: pointer to the root node of the tree to measure
 * the balance factor
 *
 * Return: balance factor or NULL if tree is empty
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int h_left = 0, h_right = 0;

	if (tree)
	{
		if (tree->left)
			h_left = _binary_tree_height(tree->left) + 1;
		if (tree->right)
			h_right = _binary_tree_height(tree->right) + 1;
		return (h_left - h_right);
	}
	return (0);
}

/**
 * _binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure
 * Return: height or NULL if tree is empty
 */
int _binary_tree_height(const binary_tree_t *tree)
{
	int h_left = 0, h_right = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	h_left = _binary_tree_height(tree->left) + 1;
	h_right = _binary_tree_height(tree->right) + 1;

	if (h_left >= h_right)
		return (h_left);
	return (h_right);
}
