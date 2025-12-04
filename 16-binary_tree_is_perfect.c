#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to root node.
 *
 * perfect_check - Helper to verify perfection.
 * @tree: Pointer to current node.
 * @depth: Expected leaf depth.
 * @level: Current level.
 *
 * Return: 1 if subtree perfect, otherwise 0.
 */
static int perfect_check(const binary_tree_t *tree, size_t depth, size_t level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (level == depth);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (perfect_check(tree->left, depth, level + 1) &&
		perfect_check(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to root node.
 *
 * Return: 1 if perfect, otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth = 0;
	const binary_tree_t *temp;

	if (tree == NULL)
		return (0);

	temp = tree;
	while (temp->left != NULL)
	{
		depth++;
		temp = temp->left;
	}

	return (perfect_check(tree, depth, 0));
}
