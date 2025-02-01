#pragma once
#include "HashTable.h"
#include "testBinF.h"

void create_hash_table(HashTable& table, ifstream& output);
Student find_el(HashTable& table, ifstream& output, string key);
void delete_el(HashTable& table, fstream& file, string key, string filename);
