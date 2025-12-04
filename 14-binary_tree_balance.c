#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to root node.
 *
 * Return: Balance factor.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_h = 1 + (int)binary_tree_height(tree->left);
	if (tree->right != NULL)
		right_h = 1 + (int)binary_tree_height(tree->right);

	return (left_h - right_h);
}
