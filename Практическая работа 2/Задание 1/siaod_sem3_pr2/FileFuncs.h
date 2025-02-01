#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
bool create_file(string file_name,ofstream &input);
bool output_file(string file_name, ifstream& output);
void add_to_file(string file_name, ofstream& input, int x);
int get_number(string file_name, ifstream& output, int index);
int get_total(string file_name, ifstream& output);
bool create_new_file(ifstream& output, string file_name, string new_file,int nod,int n);
int get_nod(string file_name);