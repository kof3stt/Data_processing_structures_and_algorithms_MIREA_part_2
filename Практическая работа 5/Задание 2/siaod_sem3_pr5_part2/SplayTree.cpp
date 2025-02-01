#include "SplayTree.h"

int SplayTree::counter = 0;
int SplayTree::compare = 0;

SplayTree* LeftRotation(SplayTree* root)
{
	root->counter++;
	SplayTree* X = root->right;
	root->right = X->left;
	X->left = root;
	return X;
}

SplayTree* RightRotation(SplayTree* root)
{
	root->counter++;
	SplayTree* X = root->left;
	root->left = X->right;
	X->right = root;
	return X;
}

SplayTree* splay(SplayTree* root, string key)
{
	// Базовые случаи: root равен NULL или
	// ключ находится в корне
	if (root == nullptr || root->data.key == key)
	{
		root->compare++;
		return root;
	}
	// Ключ может находиться в левом поддереве
	if (root->data.key.compare(key) > 0)
	{
		root->compare+=2;
		// Ключа нет в дереве, завершение
		if (root->left == nullptr) return root;
		// Zig-Zig (Левый-левый)
		if (root->left->data.key.compare(key) > 0)
		{
			root->compare++;
			// Сначала рекурсивно поднимем ключ в качестве корня left-left
			root->left->left = splay(root->left->left, key);
			// Первый поворот для root, второй поворот выполняется после else
			root = RightRotation(root);
		}
		else if (root->left->data.key.compare(key) < 0) // Zig-Zag (Left-Right)
		{
			root->compare++;
			// Сначала рекурсивно поднимаем ключ в качестве корня left-right
			root->left->right = splay(root->left->right, key);
			// Выполняем первый поворот для root->left
			if (root->left->right != nullptr)
			{
				root->compare++;
				root->left = LeftRotation(root->left);
			}
		}
		// Выполняем второй поворот для корня
		return (root->left == nullptr) ? root : RightRotation(root);
	}
	else // Ключ может находиться в правом поддереве
	{
		root->compare += 2;
		// Ключа нет в дереве, завершение
		if (root->right == nullptr) return root;
		if (root->right->data.key.compare(key) > 0) // Zag-Zig (Left-Right)
		{
			root->compare++;
			// Поднять ключ в качестве корня right-left
			root->right->left = splay(root->right->left, key);
			// Выполняем первый поворот для root->right
			if (root->right->left != nullptr) 
			{
				root->compare++;
				root->right = RightRotation(root->right);
			}
		}
		else if (root->right->data.key.compare(key) < 0)// Zag-Zag (Правый-правый)
		{
			root->compare++;
			// Поднимаем ключ в качестве корня right-right
			root->right->right = splay(root->right->right, key);
			//Выполняем первый поворот
			root = LeftRotation(root);
		}
		// Выполняем второй поворот для root
		return (root->right == nullptr) ? root : LeftRotation(root);
	}
}

SplayTree* insertToSplay(SplayTree* root, element elem)
{
	// случай 1: дерево пусто, создаем первый узел с ключом key
	if (root == nullptr)
	{
		root = new SplayTree();
		root->data.key = elem.key;
		root->data.position = elem.position;
		return root;
	}
	// случай 2. Дерево не пусто. Перемещаем ближайший узел-лист в корень
	root = splay(root, elem.key);
	//Если в корне ключ равный искомому (найден), то возвращаем дерево с этим
	//ключом в корне
	if (root->data.key == elem.key) return root;
	// Если ключа в дереве нет (ключ в корне не равен искомому), то создаем
	//новый узел
	SplayTree* newnode = new SplayTree;
	newnode->data.key = elem.key;
	newnode->data.position = elem.position;
	//Так как этот узел будет корнем, то надо определить куда перевесить
	//существующие поддеревья
	// Если ключ в корне больше искомого, делаем бывший корень правым
	//дочерним элементом нового узла,
	//делаем левый дочерний элемент бывшего корня
	//левым дочернего элемента нового узла
	if (root->data.key.compare(elem.key) > 0)
	{
		newnode->right = root;
		newnode->left = root->left;
		root->left = nullptr;
	}
	// Если ключ в корне меньше, вставляемого узла, то бывший корень дерева
	// становится левым дочерним элементом нового узла, а правый дочерний
	// элемент, бывшего корня правым дочерним элементом нового узла
	else
	{
		newnode->left = root;
		newnode->right = root->right;
		root->right = nullptr;
	}
	return newnode; // новый узел становится новым корнем
}


int delFromSplayTree(SplayTree*& root, string key)
{
	int position = INT_MIN;
	if (root == nullptr) return position; // дерево пусто
	root = splay(root, key);
	int cmp = (key == root->data.key) ? 0 : ((key.compare(root->data.key) < 0) ? -1 : 1);
	if (cmp == 0)
	{//ключ в корне
		position = root->data.position;
		if (root->left == nullptr) {
			root = root->right;
		}
		else {
			SplayTree* x = root->right;
			root = root->left;
			root = splay(root, key);
			root->right = x;
		}
	}
	return position;
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
	{
		root->compare++;
		return root->data.position;
	}
	int res = INT_MIN;
	return res;
}