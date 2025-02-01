#include "BinHash.h"
#include "HashTable.h"
void create_hash_table(HashTable& table, ifstream& file)
{
	Student Vlad;
	element elem;
	int position = 0;
	file.read((char*)&Vlad, sizeof(Student));
	while (!file.eof())
	{
		elem.pos = position;
		elem.key = Vlad.studentID;
		add_student(table, elem);
		position++;
		file.read((char*)&Vlad, sizeof(Student));
	}
}

Student find_el(HashTable& table, ifstream& file, string key)
{
	long long int n = find_student(key,table);
	return get_student(file, n);
}

void delete_el(HashTable& table, fstream& file, string key, string filename)
{
	long long int n = delete_student(key,table);
	Student* Vlad = delete_student(file, n, filename);
	if (Vlad == nullptr)
	{
		return;
	}
	if (Vlad->studentID != key)
	{
		element elem(Vlad->studentID, n);
		delete_student(elem.key,table);
		add_student(table, elem);
	}
}