#include "testBinF.h"

Student::Student()
{
    this->studentID[0] = '\0';
    this->group[0] = '\0';
    this->full_name[0] = '\0';
}

Student::~Student()
{
    this->studentID[0] = '\0';
    this->group[0] = '\0';
    this->full_name[0] = '\0';
}

void create_bin_file(ifstream& output, ofstream& input)
{
    while (!output.eof())
    {
        Student Vlad;
        char symbol;
        output.getline(Vlad.studentID, 40);
        output.getline(Vlad.group, 40);
        output.getline(Vlad.full_name, 80);
        input.write((char*)&Vlad, sizeof(Student));
    }
}

void write_from_bin_to_text(ifstream& output, ofstream& input)
{
    Student Vlad;
    output.read((char*)&Vlad, sizeof(Vlad));
    while (!output.eof())
    {
        input << Vlad.studentID << '\n'
            << Vlad.group << '\n'
            << Vlad.full_name;
        output.read((char*)&Vlad, sizeof(Vlad));
        if (!output.eof())
        {
            input << '\n';
        }
    }
}

void output_bin(ifstream& output)
{
    Student Vlad;
    output.read((char*)&Vlad, sizeof(Student));
    while (!output.eof())
    {
        cout << Vlad.studentID << " | " << Vlad.group << " | " << Vlad.full_name << "\n";
        output.read((char*)&Vlad, sizeof(Vlad));
    }
}

Student get_student(ifstream& output, int n)
{
    Student Vlad;
    output.seekg(0, ios::end);
    int size = output.tellg();
    if (n * sizeof(Student) >= size || n < 0) {
        return Student();
    }
    output.seekg(n * sizeof(Student), ios::beg);
    output.read((char*)&Vlad, sizeof(Student));
    return Vlad;
}

Student* delete_student(fstream& f, long long int n, string bin_file)
{
    f.seekg(0, ios::end);
    int size = f.tellg();
    if (n * sizeof(Student) >= size && n >= 0)
    {
        return nullptr;
    }
    Student* lastRecord = new Student(), * record = new Student();
    f.seekg((-1) * sizeof(Student), ios::end);
    f.read((char*)lastRecord, sizeof(Student));
    f.seekg(n * sizeof(Student), ios::beg);
    f.read((char*)record, sizeof(Student));
    record = lastRecord;
    f.seekg((-1) * sizeof(Student), ios::cur);
    f.write((char*)record, sizeof(Student));
    f.close();
    int desc = _open(bin_file.c_str(), O_RDWR);
    _chsize_s(desc, size - sizeof(Student));
    _close(desc);
    f.open(bin_file, ios::binary);
    return lastRecord;
}