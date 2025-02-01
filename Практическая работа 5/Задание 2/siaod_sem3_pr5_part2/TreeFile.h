#pragma once
#include "SplayTree.h"
#include "BinFile.h"

void create_splay_tree(SplayTree*& tree, ifstream& output);
Student find_el(SplayTree*& tree, ifstream& output, string key);
void delete_el(SplayTree*& tree, fstream& file, string key, string filename);