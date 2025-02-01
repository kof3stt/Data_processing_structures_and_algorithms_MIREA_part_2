// siaod_sem3_pr8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

string RLE(string str)
{
    string encoding = "";
    int count;
    for (int i = 0; str[i]; i++)
    {
        count = 1;
        while (str[i] == str[i + 1]) {
            count++, i++;
        }
        encoding += to_string(count) + str[i];
    }
    return encoding;
}

string SUPER_RLE(string s)
{
	string res = "", group = s.substr(0, 1);
	int count = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == s[i - 1]) {
			if (group.size() > 1) {
				res += to_string(count + 1) + group.substr(0, -count - 1);
				count = 1;
			}
			group = "";
			count++;
		}
		else {
			if (count >= 2) {
				res += to_string(count) + s[i - 1];
				count = 1;
			}
			else if (count == 1) {
				count = -2;
			}
			else {
				count--;
			}
			group += s[i];
		}
	}
	if (group.size() > 1) {
		res += to_string(count + 1) + group.substr(0, -count - 1);
	}
	else {
		res += to_string(count) + s[s.size() - 1];
	}
	return res;
}

int main()
{
    system("chcp 1251");
	string test = "XYZXYZXYZXYZVVVVVVZYZYZY";
	cout << "Исходная строка: " << test << endl;
    cout << "Результат кодированяи методов RLE: " << RLE(test) << endl;
	cout << "Продвинутый метод RLE: " << SUPER_RLE(test) << endl;
	cout << " Длина исходной строки: " << size(test) << endl;
	cout << " Длина при кодировании RLE: " << size(RLE(test)) << endl;
	cout << " Длина при кодировании продвинутым RLE: " << size(SUPER_RLE(test)) << endl;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
