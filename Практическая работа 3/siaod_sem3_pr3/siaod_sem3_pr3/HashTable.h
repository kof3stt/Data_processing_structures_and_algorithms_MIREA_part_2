#pragma once
#include <iostream>
#include <string>
using namespace std;

struct element
{
	string key;
	long long int pos;
	bool is_busy = 0;
	bool is_deleted = 0;
	int attempt = 0;
	element();
	element(string key, long long int pos);
};

struct HashTable 
{
	int counter = 0;
	long long int total = 0;
	long long int size = 10;
	element* data = new element[size];
	HashTable();
};

unsigned long long hash_func1(string key, unsigned long long int size);
unsigned long long hash_func2(string key, unsigned long long int size);
void add_student(HashTable& table, element elem);
void print_hash_table(const HashTable& table);
long long int find_student(string key, HashTable& table);
long long int delete_student(string key, HashTable& table);
void rehash_table(HashTable& table);