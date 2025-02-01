#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <fcntl.h>
#include <io.h>
using namespace std;

struct Student
{
	char studentID[40];
	char group[40];
	char full_name[80];
	Student();
	~Student();
};

void create_bin_file(ifstream& output, ofstream& input);
void output_bin(ifstream& output);
Student get_element(ifstream& output, int n);
Student* delete_element(fstream& f, long long int n, string bin_file);