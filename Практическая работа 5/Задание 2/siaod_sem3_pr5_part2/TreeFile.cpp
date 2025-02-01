#include "TreeFile.h"

void create_splay_tree(SplayTree*& tree, ifstream& file)
{
	Student Vlad;
	element elem;
	int pos = 0;
	file.read((char*)&Vlad, sizeof(Student));
	while (!file.eof())
	{
		elem.position = pos;
		elem.key = Vlad.studentID;
		tree = insertToSplay(tree, elem);
		pos++;
		file.read((char*)&Vlad, sizeof(Student));
	}
}

Student find_el(SplayTree*& tree, ifstream& file, string key)
{
	tree->compare = 0;
	long long int n = find_element(tree, key);
	if (n == INT_MIN)
		return Student();
	return get_element(file, n);
}

void delete_el(SplayTree*& tree, fstream& file, string key, string filename)
{
	long long int n = delFromSplayTree(tree, key);
	Student* Vlad = delete_element(file, n, filename);
	if (Vlad == nullptr)
	{
		return;
	}
	if (Vlad->studentID != key)
	{
		find_element(tree, Vlad->studentID) = n;
	}
}