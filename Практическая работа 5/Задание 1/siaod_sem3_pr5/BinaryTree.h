#pragma once
#include "BinFile.h"

struct element
{
	string key;
	int position = INT_MIN;
	element() {}
	element(string key, int position) : key(key), position(position) {}
};

struct BinaryTree
{
	static int compare;
	element data;
	BinaryTree* left = nullptr;
	BinaryTree* right = nullptr;
	BinaryTree(element elem) : data(elem) {}
};

int& find_element(BinaryTree* root, string key);
void add_element(BinaryTree*& root, element elem);
int delete_element(BinaryTree*& root, string key);
int delete_element(BinaryTree*& root, string key, BinaryTree*& parent);
void find_replace(BinaryTree*& replace, BinaryTree*& parentReplace);
void print_tree(BinaryTree* node, int level = 0);
