#include "FileFuncs.h";
int main()
{
    int num;
    string file_name;
    string new_file;
    ofstream input;
    ifstream output;
    system("chcp 1251");
    while (true)
    {
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        cout << " Меню\n";
        cout << " 1. Создать и заполнить текстовый файл\n";
        cout << " 2. Вывести содержимое текствого файла\n";
        cout << " 3. Добавить новую запись в конец файла\n";
        cout << " 4. Прочитать значение числа, указав его порядковый номер в файле, и вернуть его значение\n";
        cout << " 5. Определить количество чисел в файле\n";
        cout << " 6. Создать новый файл из значений исходного, поделив каждое число на наибольший общий делитель чисел файла\n";
        cout << " 7. Завершение работы программы\n";
        cin >> num;
        switch (num)
        {
        case 1:
            cout << " Введите название файла: ";
            cin >> file_name;
            input.open(file_name);
            if (!input)
            {
                cout << " Файл не открыт\n";
                break;
            }
            else
            {
                create_file(file_name,input);
                if (!input)
                {
                    cout << " Ошибка при работе с файлом!\n";
                    return -1;
                }
                input.close();
            }
            break;
        case 2:
            cout << " Введите название файла: ";
            cin >> file_name;
            output.open(file_name);
            if (!output)
            {
                cout << " Файл не открыт или файла не существует\n";
                break;
            }
            else
            {
                output_file(file_name,output);
                cout << endl;
                if (!output)
                {
                    cout << " Ошибка при работе с файлом!\n";
                }
                output.close();
            }
            break;
        case 3:
            cout << " Введите название файла: ";
            cin >> file_name;
            input.open(file_name, ios::out | ios::app);
            if (!input)
            {
                cout << " Файл не открыт\n";
                break;
            }
            else
            {
                cout << " Введите число для добавления в конец файла: ";
                cin >> num;
                add_to_file(file_name, input,num);
                if (!input)
                {
                    cout << " Ошибка при работе с файлом!\n";
                }
                input.close();
            }
            break;
        case 4:
            cout << " Введите название файла: ";
            cin >> file_name;
            output.open(file_name);
            if (!output)
            {
                cout << " Файл не открыт или файла не существует\n";
                break;
            }
            else
            {
                cout << " Введите индекс, по которому нужно вернуть значение: ";
                cin >> num;
                int res = get_number(file_name, output, num);
                if (res == -1)
                {
                    cout << " IndexError\n";
                }
                else
                {
                    cout << " Значение по заданному индексу: " << res << endl;
                }
                if (!output)
                {
                    cout << " Ошибка при работе с файлом!\n";
                }
                output.close();
            }
            break;
        case 5:
            cout << " Введите название файла: ";
            cin >> file_name;
            output.open(file_name);
            if (!output)
            {
                cout << " Файл не открыт или файла не существует\n";
                break;
            }
            else
            {
                cout << " Всего чисел: " << get_total(file_name, output) << endl;
                if (!output)
                {
                    cout << " Ошибка при работе с файлом!\n";
                }
                output.close();
            }
            break;
        case 6:
            cout << " Введите название файла, на основе которого будет сгенерирован новый файл: ";
            cin >> file_name;
            output.open(file_name);
            if (!output)
            {
                cout << " Файл не открыт или файла не существует\n";
                break;
            }
            else
            {
                cout << " Введите название нового файла, куда будет записан результат: ";
                cin >> new_file;
                int nod = get_nod(file_name);
                if (nod != -1)
                {
                    ifstream sss;
                    sss.open(file_name);
                    create_new_file(output, file_name, new_file,nod,get_total(file_name,sss));
                    if (!sss)
                    {
                        cout << " Ошибка при работе с файлом!\n";
                    }
                    sss.close();
                }
                else
                {
                    cout << " Пустой файл\n";
                }
                if (!output)
                {
                    cout << " Ошибка при работе с файлом!\n";
                }
                output.close();
            }
            break;
        case 7:
            return 0;
        default:
            cout << " Нет такого пункта\n";
        }
    }
    return 0;
}