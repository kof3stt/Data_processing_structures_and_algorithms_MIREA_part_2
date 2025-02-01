#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <io.h>
#include <windows.h>
#include <fcntl.h>
#include <share.h>
#include <sys/stat.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
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
void write_from_bin_to_text(ifstream& output, ofstream& input);
void output_bin(ifstream& output);
bool get_student(ifstream& output, int n, Student& stud);
void delete_student(fstream& f, string id, string bin_file);
void one_group(ifstream& output, ofstream& input, string new_group);
void move_students(fstream& f, ifstream& output, string new_group);