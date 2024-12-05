#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t **queue;
	binary_tree_t *current;
	int front = 0, rear = 0, flag = 0;

	if (tree == NULL)
		return (0);
	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return (0);
	queue[rear++] = (binary_tree_t *)tree;
	while (front < rear)
	{
		current = queue[front++];

		if (current->left != NULL)
		{
			if (flag)
			{
				free(queue);
				return (0);
			}
			queue[rear++] = current->left;
		}
		else
			flag = 1;

		if (current->right != NULL)
		{
			if (flag)
			{
				free(queue);
				return (0);
			}
			queue[rear++] = current->right;
		}
		else
			flag = 1;
	}
	free(queue);
	return (1);
}
