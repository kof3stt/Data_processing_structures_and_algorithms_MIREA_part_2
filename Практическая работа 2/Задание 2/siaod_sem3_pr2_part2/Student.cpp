#include "Student.h"

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
        int i = 0;
        output.get(Vlad.studentID[i]);
        while (Vlad.studentID[i] != '\n')
        {
            i++;
            output.get(Vlad.studentID[i]);
        }
        Vlad.studentID[i] = '\0';
        
        i = 0;
        output.get(Vlad.group[i]);
        while (Vlad.group[i] != '\n')
        {
            i++;
            output.get(Vlad.group[i]);
        }
        Vlad.group[i] = '\0';

        i = 0;
        output.get(Vlad.full_name[i]);
        while (Vlad.full_name[i] != '\n' and !output.eof())
        {
            i++;
            output.get(Vlad.full_name[i]);
        }
        Vlad.full_name[i] = '\0';

        input.write((char*)&Vlad, sizeof(Vlad));
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

bool get_student(ifstream& output,int n,Student& stud)
{
    output.seekg(n * sizeof(Student), ios::beg);
    if (!output.bad())
    { 
        output.read((char*)&stud, sizeof(Student));
        return 0;
    }
    return 1;
}

void delete_student(fstream& f, string id, string bin_file) 
{
    f.seekg((-1) * sizeof(Student), std::ios::end);
    Student Vlad;
    f.read((char*)&Vlad, sizeof(Student));
    bool ok = false;
    f.seekg(0, std::ios::beg);
    while (true) 
    {
        Student V;
        f.read((char*)&V, sizeof(Student));
        if (f.eof()) 
        {
            break;
        }
        if (V.studentID == id) 
        {
            f.seekg((-1)*sizeof(Student), std::ios::cur);
            f.write((char*)&Vlad, sizeof(Student));
            ok = true;
            break;
        }
    }
    f.seekg(0, std::ios::end);
    int size = f.tellg();
    f.close();
    if (!ok) 
    {
        return;
    }
    int x;
    errno_t r = _sopen_s(&x, bin_file.c_str(), _O_RDWR, _SH_DENYNO, _S_IREAD | _S_IWRITE);
    if (!r) 
    {
        _chsize(x, size - sizeof(Student));
        _close(x);
    }
}

void one_group(ifstream& output, ofstream& input, string new_group)
{
    Student Vlad;
    output.read((char*)&Vlad, sizeof(Student));
    while (!output.eof())
    {
        if (Vlad.group == new_group)
        {
            input << Vlad.studentID << '\n'
                << Vlad.group << '\n'
                << Vlad.full_name;
            output.read((char*)&Vlad, sizeof(Student));
            if (!output.eof())
            {
                input << '\n';
            }
        }
        else
            output.read((char*)&Vlad, sizeof(Student));
    }
}

void move_students(fstream& f, ifstream& output, string new_group)
{
    vector <string> data;
    string z;
    while (!output.eof())
    {
        output >> z;
        data.push_back(z);
    }
    while (!f.eof())
    {
        Student Vlad;
        f.read((char*)&Vlad, sizeof(Student));
        if (f.eof())
        {
            break;
        }
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == Vlad.studentID)
            {
                strcpy(Vlad.group, new_group.c_str());
                f.seekg((-1) * sizeof(Student), ios::cur);
                f.write((char*)&Vlad, sizeof(Student));
            }
        }
    }
}