#pragma once
#include "BinaryTree.h"
#include "BinFile.h"

void create_binary_tree(BinaryTree*& tree, ifstream& output);
Student find_el(BinaryTree*& tree, ifstream& output, string key);
void delete_el(BinaryTree*& tree, fstream& file, string key, string filename);