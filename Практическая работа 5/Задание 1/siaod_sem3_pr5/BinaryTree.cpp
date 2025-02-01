#include "BinaryTree.h"


void add_element(BinaryTree*& root, element elem)
{
	if (root == nullptr)
	{
		root = new BinaryTree(elem);
	}
	else
	{
		if (elem.key.compare(root->data.key)<0)
		{
			add_element(root->left, elem);
		}
		else if (elem.key.compare(root->data.key) >0)
		{
			add_element(root->right, elem);
		}
	}
}

void print_tree(BinaryTree* tree, int level)
{
	if (tree != nullptr)
	{
		level += 12;
		print_tree(tree->right, level);
		cout << endl;
		for (int i = 0; i < level; i++)
			cout << " ";
		cout << tree->data.key << "\n";
		print_tree(tree->left, level);
	}
}


int& find_element(BinaryTree* root, string key)
{
	if (root == nullptr)
	{
		root->compare++;
		int res = INT_MIN;
		return res;
	}

	if (root->data.key == key)
	{
		root->compare++;
		return root->data.position;
	}

	else if (key.compare(root->data.key)<0)
	{
		root->compare++;
		return find_element(root->left, key);
	}
	else
	{
		root->compare++;
		return find_element(root->right, key);
	}
}

int delete_element(BinaryTree*& root, string key)
{
	BinaryTree* parent = nullptr;
	int res = delete_element(root, key, parent);
	return res;
}

int delete_element(BinaryTree*& root, string key, BinaryTree*& parent)
{
	if (root == nullptr)
	{
		return INT_MIN;
	}
	if (key.compare(root->data.key)<0)
	{
		parent = root;
		int res = delete_element(root->left, key, parent);
		return res;
	}
	else if (key.compare(root->data.key) > 0)
	{
		parent = root;
		int res = delete_element(root->right, key, parent);
		return res;
	}

	else
	{
		int position = root->data.position;
		BinaryTree* deleted = root, * replace = nullptr, * parentReplace = nullptr;
		if (root->left == nullptr && root->right == nullptr)
		{
			if (parent == nullptr)
			{
				root = replace;
			}
			else if (parent->left == deleted)
			{
				parent->left = nullptr;
				delete deleted;
			}
			else if (parent->right == deleted)
			{
				parent->right = nullptr;
				delete deleted;
			}
		}
		else if (root->left != nullptr && root->right == nullptr)
		{
			replace = deleted->left;
			if (parent == nullptr)
			{
				root = replace;
			}
			else if (parent->left == deleted)
			{
				parent->left = replace;
				delete deleted;
			}
			else if (parent->right == deleted)
			{
				parent->right = replace;
				delete deleted;
			}
		}
		else if (root->right != nullptr && root->left == nullptr)
		{
			replace = deleted->right;
			if (parent == nullptr)
			{
				root = replace;
			}
			else if (parent->left == deleted)
			{
				parent->left = replace;
			}
			else if (parent->right == deleted)
			{
				parent->right = replace;
			}
			delete deleted;
		}
		else
		{
			replace = deleted->left;
			if (replace->right == nullptr)
			{
				replace->right = deleted->right;
			}
			else
			{
				parentReplace = deleted->left;
				replace = replace->right;
				find_replace(replace, parentReplace);
				replace->left = deleted->left;
				replace->right = deleted->right;
			}

			if (parent == nullptr)
			{
				root = replace;
			}

			else if (parent->left == deleted)
			{
				parent->left = replace;
			}
			else if (parent->right == deleted)
			{
				parent->right = replace;
			}
			delete deleted;
		}
		return position;
	}
}

void find_replace(BinaryTree*& replace, BinaryTree*& parentReplace)
{
	if (replace->right != nullptr)
	{
		parentReplace = parentReplace->right;
		replace = replace->right;
		find_replace(replace, parentReplace);
	}
	else
	{
		parentReplace->right = replace->left;
		replace->left = nullptr;
	}
}