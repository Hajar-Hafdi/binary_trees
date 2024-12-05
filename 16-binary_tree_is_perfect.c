#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_h - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: The height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_h(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = tree->left ? 1 + binary_tree_h(tree->left) : 0;
	size_t right_height = tree->right ? 1 + binary_tree_h(tree->right) : 0;

	return (left_height > right_height ? left_height : right_height);
}

/**
 * binary_tree_s - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: The size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_s(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_s(tree->left) + binary_tree_s(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t height = binary_tree_h(tree);
	size_t size = binary_tree_s(tree);

	/* A perfect binary tree of height h has (2^(h+1) - 1) nodes */
	size_t perfect_size = (1 << (height + 1)) - 1;

	return (size == perfect_size);
}
