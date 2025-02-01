#include "Student.h"
int main()
{
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_CTYPE, "Russian");
    string text_file;
    string bin_file;
    string new_file;
    string new_group;
    string id;
    ifstream output;
    ofstream input;
    ofstream newfile;
    fstream f;
    int num;
    int n;
    int key_work;
    Student stud;
    system("chcp 1251");
    while (true)
    {
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        cout << " Меню\n";
        cout << " 1. Преобразовать текстовый файл в двоичный\n";
        cout << " 2. Вывести содержимое двоичного файла в текстовый\n";
        cout << " 3. Вывести содержимое двоичного файла в консоль\n";
        cout << " 4. Получение записи из двоичного файла по порядковому номеру\n";
        cout << " 5. Удаление записи по ключу\n";
        cout << " 6. Сформировать список студентов одной группы\n";
        cout << " 7. Перевести некоторых студентов в другую группу\n";
        cout << " 8. Завершение работы программы\n";
        cin >> num;
        switch (num)
        {
        case 1:
            cout << " Введите название текстового файла: ";
            cin >> text_file;
            cout << " Введите название двоичного файла: ";
            cin >> bin_file;
            output.open(text_file);
            if (!output.is_open())
            {
                cout << " Текстовый файл не открыт\n";
            }
            else
            {
                input.open(bin_file, ios::binary);
                create_bin_file(output, input);
                if (!input.good())
                {
                    cout << " Ошибка записи в двоичный файл\n";
                    return -1;
                }
                else
                {
                    output.close();
                    input.close();
                }
            }
            break;
        case 2:
            cout << " Введите название двоичного файла: ";
            cin >> bin_file;
            cout << " Введите название текстового файла: ";
            cin >> text_file;
            output.open(bin_file, ios::binary);
            if (!output.is_open())
            {
                cout << " Двоичный файл не открыт\n";
            }
            else
            {
                input.open(text_file);
                write_from_bin_to_text(output, input);
                if (!input)
                {
                    cout << " Ошибка записи в текстовый файл\n";
                    return -1;
                }
                else
                {
                    output.close();
                    input.close();
                }
            }
            break;
        case 3:
            cout << " Введите название двоичного файла: ";
            cin >> bin_file;
            output.open(bin_file, ios::binary);
            if (!output.is_open())
            {
                cout << " Двоичный файл не открыт\n";
            }
            else
            {
                output_bin(output);
                if (output.bad())
                {
                    cout << " Ошибка при чтении из двоичного файла\n";
                }
                else
                {
                    output.close();
                }
            }
            break;
        case 4:
            cout << " Введите название двоичного файла: ";
            cin >> bin_file;
            output.open(bin_file, ios::binary);
            if (output.is_open())
            {
                cout << " Введите номер записи: ";
                cin >> n;
                key_work = get_student(output, n, stud);
                if (key_work == 1 or stud.studentID[0] == '\0')
                {
                    cout << " Записи с заданным номером не существует\n";
                }
                else
                {
                    cout << " " << stud.studentID << " | " << stud.group << " | " << stud.full_name << endl;
                    stud.~Student();
                }
                output.close();
            }
            else
            {
                cout << " Двоичный файл не существует\n";
            }
            break;

        case 5:
            cout << " Введите название двоичного файла: ";
            cin >> bin_file;
            f.open(bin_file);
            if (f.is_open())
            {
                cout << " Введите номер зачетной книжки: ";
                cin >> id;
                delete_student(f,id,bin_file);
                f.close();
            }
            else
            {
                cout << " Двоичный файл не существует\n";
            }
            break;
        case 6:
            cout << " Введите название двоичного файла, где записана информация о студентах:  ";
            cin >> bin_file;
            output.open(bin_file, ios::binary);
            if (output.is_open())
            {
                cout << " Введите название нового файла, где будет сформирован список студентов одной группы: ";
                cin >> new_file;
                new_file += ".txt";
                input.open(new_file);
                if (!input.is_open())
                {
                    cout << " Двоичный файл для записи не открыт\n";
                }
                else
                {
                    cout << " Введите номер группы для создания нового файла со студентами этой группы: ";
                    cin >> new_group;
                    one_group(output, input, new_group);
                    if (input.bad())
                    {
                        cout << " Ошибка при записи из двоичного файла в двоичный\n";
                    }
                    else
                    {
                        input.close();
                    }
                }
                output.close();
                output.open(new_file);
                string t = new_file.substr(0, new_file.size() - 4);
                input.open(t, ios::binary);
                create_bin_file(output, input);
                output.close();
                input.close();
            }
            else
            {
                cout << " Двоичный файл не существует\n";
            }
            break;
        case 7:
            cout << " Введите название двоичного файла: ";
            cin >> bin_file;
            f.open(bin_file);
            if (f.is_open())
            {
                cout << " Введите название текстового файла, где храянтся номера зачеток: ";
                cin >> text_file;
                output.open(text_file);
                if (output.is_open())
                {
                    cout << " Введите номер новой группы: ";
                    cin >> new_group;
                    move_students(f, output, new_group);
                    output.close();
                }
                else
                {
                    cout << " Текстовый файл не существует\n";
                }
                f.close();
            }
            else
            {
                cout << " Двоичный файл не существует\n";
            }
            break;
        case 8:
            return 0;
        default:
            cout << " Нет такого пункта\n";
        }
    }
    return 0;
}