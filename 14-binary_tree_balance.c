#include "binary_trees.h"

/**
 * balance_height - Measures height of a binary tree.
 * @tree: Pointer to root node.
 *
 * Return: Height or 0 if tree is NULL.
 */
static size_t balance_height(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		left_h = 1 + balance_height(tree->left);
	if (tree->right != NULL)
		right_h = 1 + balance_height(tree->right);

	return (left_h > right_h ? left_h : right_h);
}

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
		left_h = 1 + (int)balance_height(tree->left);
	if (tree->right != NULL)
		right_h = 1 + (int)balance_height(tree->right);

	return (left_h - right_h);
}
