#include "binary_trees.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * binary_tree_nodes - counts the nodes in a binary tree
 * with atleast i child
 * @tree: pointer to the root node of the tree to count
 * the number of nodes
 *
 * Return: size or NULL if tree is empty
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t no_node = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);
	no_node++;
	no_node += binary_tree_nodes(tree->left);
	no_node += binary_tree_nodes(tree->right);
	return (no_node);
}
