// siaod_sem3_pr1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <bitset>
#include <iostream>
#include <sstream>
using namespace std;

void bin2(int n)
{
    if (n == 0)
    {
        return;
    }
    bin2(n >> 1);
    cout << (n & 1);
}

void bin(int n)
{
    bitset <16> bits(n);
    cout << bits << endl;
}

void task_6(int x, int y, int n, int p)
{
    
}

unsigned short task_1(unsigned int x)
{
    return x | (1 << 7 | 1 << 9 | 1 << 11);
}

unsigned short task_2(unsigned int x)
{
    unsigned short int maska = 0xAAAA;
    return x & maska;
}

unsigned short task_3(unsigned int x)
{
    return x << 7;
}

unsigned short task_4(unsigned int x)
{
    return x >> 7;
}

unsigned short task_5(unsigned int x, int num)
{
    unsigned short int maska = 1;
    return x & (~(maska << num));
}

int main()
{
    system("chcp 1251");
    /*
    int num;
    unsigned short int x;
    unsigned short int maska;
    while (true)
    {
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        cout << " Меню\n";
        cout << " 1. Установить 7-ой, 9-ый, 11-ый биты в единицу\n";
        cout << " 2. Обнулить биты с четными номерами\n";
        cout << " 3. Умножить число на 128, используя поразрядную операцию\n";
        cout << " 4. Разделить число на 128, используя поразрядную операцию\n";
        cout << " 5. Обнулить n-ый бит\n";
        cout << " 6. Завершить работу\n";
        cin >> num;
        switch (num)
        {
        case 1:
            cout << " Введите число: ";
            cin >> x;
            cout << "Результат: ";
            cout << int(task_1(x)) << ' ';
            bin(task_1(x));
            break;
        case 2:
            cout << " Введите число: ";
            cin >> x;
            cout << "Результат: ";
            cout << int(task_2(x)) << ' ';
            bin(task_2(x));
            break;
        case 3:
            cout << " Введите число: ";
            cin >> x;
            cout << "Результат: ";
            cout << int(task_3(x)) << ' ';
            bin(task_3(x));
            break;
        case 4:
            cout << " Введите число: ";
            cin >> x;
            cout << "Результат: ";
            cout << int(task_4(x)) << ' ';
            bin(task_4(x));
            break;
        case 5:
            cout << " Введите число: ";
            cin >> x;
            cout << " Введите номер бита, который требуется обнулить\n";
            cin >> num;
            cout << "Результат: ";
            cout << int(task_5(x,num)) << ' ';
            bin(task_5(x,num));
            break;
        case 6:
            return 0;
        default:
            cout << " Нет такого пункта\n";
        }
    }
    */
    bin2(125);
    cout << endl;
    bin(125);
}