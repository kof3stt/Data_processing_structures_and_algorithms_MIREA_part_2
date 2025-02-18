#include "SplayTree.h"

SplayTree* LeftRotation(SplayTree* root)
{
	SplayTree* X = root->right;
	root->right = X->left;
	X->left = root;
	return X;
}

SplayTree* RightRotation(SplayTree* root)
{
	SplayTree* X = root->left;
	root->left = X->right;
	X->right = root;
	return X;
}

SplayTree* splay(SplayTree* root, string key)
{
	// ������� ������: root ����� NULL ���
	// ���� ��������� � �����
	if (root == nullptr || root->data.key == key)
		return root;
	// ���� ����� ���������� � ����� ���������
	if (root->data.key.compare(key) > 0)
	{
		// ����� ��� � ������, ����������
		if (root->left == nullptr) return root;
		// Zig-Zig (�����-�����)
		if (root->left->data.key.compare(key) > 0)
		{
			// ������� ���������� �������� ���� � �������� ����� left-left
			root->left->left = splay(root->left->left, key);
			// ������ ������� ��� root, ������ ������� ����������� ����� else
			root = RightRotation(root);
		}
		else if (root->left->data.key.compare(key) < 0) // Zig-Zag (Left-Right)
		{
			// ������� ���������� ��������� ���� � �������� ����� left-right
			root->left->right = splay(root->left->right, key);
			// ��������� ������ ������� ��� root->left
			if (root->left->right != nullptr)
				root->left = LeftRotation(root->left);
		}
		// ��������� ������ ������� ��� �����
		return (root->left == nullptr) ? root : RightRotation(root);
	}
	else // ���� ����� ���������� � ������ ���������
	{
		// ����� ��� � ������, ����������
		if (root->right == nullptr) return root;
		if (root->right->data.key.compare(key) > 0) // Zag-Zig (Left-Right)
		{
			// ������� ���� � �������� ����� right-left
			root->right->left = splay(root->right->left, key);
			// ��������� ������ ������� ��� root->right
			if (root->right->left != nullptr)
				root->right = RightRotation(root->right);
		}
		else if (root->right->data.key.compare(key) < 0)// Zag-Zag (������-������)
		{
			// ��������� ���� � �������� ����� right-right
			root->right->right = splay(root->right->right, key);
			//��������� ������ �������
			root = LeftRotation(root);
		}
		// ��������� ������ ������� ��� root
		return (root->right == nullptr) ? root : LeftRotation(root);
	}
}

SplayTree* insertToSplay(SplayTree* root, element elem)
{
	// ������ 1: ������ �����, ������� ������ ���� � ������ key
	if (root == nullptr)
	{
		root = new SplayTree();
		root->data.key = elem.key;
		root->data.position = elem.position;
		return root;
	}
	// ������ 2. ������ �� �����. ���������� ��������� ����-���� � ������
	root = splay(root, elem.key);
	//���� � ����� ���� ������ �������� (������), �� ���������� ������ � ����
	//������ � �����
	if (root->data.key == elem.key) return root;
	// ���� ����� � ������ ��� (���� � ����� �� ����� ��������), �� �������
	//����� ����
	SplayTree* newnode = new SplayTree;
	newnode->data.key = elem.key;
	newnode->data.position = elem.position;
	//��� ��� ���� ���� ����� ������, �� ���� ���������� ���� ����������
	//������������ ����������
	// ���� ���� � ����� ������ ��������, ������ ������ ������ ������
	//�������� ��������� ������ ����,
	//������ ����� �������� ������� ������� �����
	//����� ��������� �������� ������ ����
	if (root->data.key.compare(elem.key) > 0)
	{
		newnode->right = root;
		newnode->left = root->left;
		root->left = nullptr;
	}
	// ���� ���� � ����� ������, ������������ ����, �� ������ ������ ������
	// ���������� ����� �������� ��������� ������ ����, � ������ ��������
	// �������, ������� ����� ������ �������� ��������� ������ ����
	else
	{
		newnode->left = root;
		newnode->right = root->right;
		root->right = nullptr;
	}
	return newnode; // ����� ���� ���������� ����� ������
}

int delFromSplayTree(SplayTree*& root, string key)
{
	int res = INT_MIN;
	if (root == nullptr) return res; // ������ �����
	root = splay(root, key);
	if (root->data.key == key)
		res = root->data.position;
	int cmp = (key == root->data.key) ? 0 : ((key.compare(root->data.key)<0) ? -1 : 1);
	if (cmp == 0)
	{//���� � �����
		if (root->left == nullptr)
		{
			root = root->right;
		}
		else
		{
			SplayTree* x = root->right;
			root = root->left;
			root = splay(root, key);
			root->right = x;
		}
	}
	return res;
}

void print_tree(SplayTree* tree, int level)
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

int& find_element(SplayTree*& root, string key)
{
	root = splay(root, key);
	if (root->data.key == key)
		return root->data.position;
	int res = INT_MIN;
	return res;
}
