#include "TreeFile.h"
int BinaryTree::compare;
void create_binary_tree(BinaryTree*& tree, ifstream& file)
{
	Student Vlad;
	element elem;
	int pos = 0;
	file.read((char*)&Vlad, sizeof(Student));
	while (!file.eof())
	{
		elem.position = pos;
		elem.key = Vlad.studentID;
		add_element(tree, elem);
		pos++;
		file.read((char*)&Vlad, sizeof(Student));
	}
}

Student find_el(BinaryTree*& tree, ifstream& file, string key)
{
	BinaryTree::compare = 0;
	long long int n = find_element(tree, key);
	if (n == INT_MIN)
		return Student();
	return get_element(file, n);
}

void delete_el(BinaryTree*& tree, fstream& file, string key, string filename)
{
	long long int n = delete_element(tree, key);
	Student* Vlad = delete_element(file, n, filename);
	if (Vlad == nullptr)
	{
		return;
	}
	if (Vlad->studentID != key)
	{
		element elem(Vlad->studentID, n);
		delete_element(tree,elem.key);
		add_element(tree, elem);
	}
}