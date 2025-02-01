/*
#include "HashTable.h"
#include "testBinF.h"
int main()
{
	system("chcp 1251");
	HashTable table;
	int num;
	long long int position = 0;
	long long int res = 0;
	string key;
	while (true)
	{
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << " Меню\n";
		cout << " 1. Добавить элемент в таблицу\n";
		cout << " 2. Вывести хеш-таблицу\n";
		cout << " 3. Найти элемент по ключу в таблице\n";
		cout << " 4. Удалить элемент по ключу из таблицы\n";
		cout << " 5. Завершить выполнение программы\n";
		cin >> num;
		switch (num)
		{
		case 1:
		{
			cout << " Введите ключ записи: ";
			cin.get();
			getline(cin, key);
			element elem(key, position++);
			add_student(table, elem);
			break;
		}
		case 2:
		{
			print_hash_table(table);
			break;
		}
		case 3:
		{
			cout << " Введите ключ для поиска: ";
			cin >> key;
			res = find_student(key, table);
			if (res == -1)
				cout << " Элемент не найден\n";
			else cout << res << endl;
			break;
		}
		case 4:
		{
			cout << " Введите ключ для поиска: ";
			cin >> key;
			res = delete_student(key, table);
			if (res == -1)
				cout << " Элемент не найден\n";
			break;
		}
		case 5:
		{
			return 0;
		}
		default:
		{
			cout << " Нет такого пункта\n";
		}
		}
	}
}
*/


#include "BinHash.h"
#include "HashTable.h"
int main()
{
	system("chcp 1251");
	HashTable table;
	int num;
	ifstream output;
	ofstream input;
	string first_file, second_file;
	fstream f;
	string key;
	while (true)
	{
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << " Меню\n";
		cout << " 1. Преобразовать текстовый файл в двоичный\n";
		cout << " 2. Перевод двоичного файла в хэш-таблицу\n";
		cout << " 3. Поиск записи\n";
		cout << " 4. Удаление записи\n";
		cout << " 5. Вывести хэш-таблицу\n";
		cout << " 6. Вывести содержимое двоичного файла в консоль\n";
		cout << " 7. Завершить выполнение программы\n";
		cin >> num;
		switch (num)
		{
		case 1:
		{
			cout << " Введите название текстового файла: ";
			cin >> first_file;
			cout << " Введите название двоичного файла: ";
			cin >> second_file;
			output.open(first_file);
			if (!output.is_open())
			{
				cout << " Текстовый файл не открыт\n";
			}
			else
			{
				input.open(second_file, ios::binary);
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
		}
		case 2:
		{
			cout << " Введите название двоичного файла: ";
			cin >> first_file;
			output.open(first_file, ios::binary);
			if (output.is_open())
			{
				create_hash_table(table, output);
				if (output.bad())
				{
					cout << " Возникла ошибка создания хэш-таблицы\n";
					return 1;
				}
				else
				{
					cout << " Создание хэш-таблицы произошло успешно\n";
					output.close();
				}
			}
			else
			{
				cout << " Двоичного файла не существует\n";
			}
			break;
		}
		case 3:
		{
			cout << " Введите название двоичного файла: ";
			cin >> first_file;
			output.open(first_file, ios::binary);
			if (output.is_open())
			{
				cout << "Введите номер зачетной книжки: ";
				cin.get();
				getline(cin, key);
				auto start = chrono::high_resolution_clock::now();
				Student stud = find_el(table, output, key);
				auto end = chrono::high_resolution_clock::now();
				cout << " Время поиска: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / 1e6 << " мс\n";
				cout << " Количество сравнений: " << table.counter << endl;
				if (output.bad())
				{
					cout << " Возникла ошибка чтения\n";
					return 1;
				}
				else
				{
					if (stud.group[0] != '\0')
						cout << stud.studentID << " | " << stud.group << " | " << stud.full_name << "\n";
					else
						cout << " Запись не найдена\n";
					output.close();
				}
			}
			else
			{
				cout << " Двоичный файл не существует\n";
			}
			break;
		}
		case 4:
		{
			cout << "Введите название двоичного файла: ";
			cin >> first_file;
			f.open(first_file, ios::in | ios::out | ios::binary);
			if (f.is_open())
			{
				string key;
				cout << " Введите номер зачетной книжки: ";
				cin.get();
				getline(cin, key);
				delete_el(table, f, key, first_file);
				if (output.bad())
				{
					cout << " Возникла ошибка при удалении\n";
					return 1;
				}
				else
				{
					cout << " Запись успешно удалена!\n";
					f.close();
				}
			}
			else
			{
				cout << " Двоичный файл не существует\n";
			}
			break;
		}
		case 5:
		{
			print_hash_table(table);
			break;
		}
		case 6:
		{
			cout << " Введите название двоичного файла: ";
			cin >> first_file;
			output.open(first_file, ios::binary);
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
					return 1;
				}
				else
				{
					output.close();
				}
			}
			break;
		}
		case 7:
			return 0;
		default:
		{
			cout << " Нет такого пункта\n";
		}
		}
	}
}