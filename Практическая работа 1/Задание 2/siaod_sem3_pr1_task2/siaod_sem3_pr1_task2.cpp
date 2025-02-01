// siaod_sem3_pr1_task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <chrono>
#include <bitset>
using namespace std;

const int N = 10000000;

void create_array(unsigned char* arr)
{
    for (int i = 0; i < (N >> 3) + 1; i++)
    {
        arr[i] = 0;
    }
}

void my_sort(unsigned char* arr)
{
    unsigned maska = 1;
    for (int i = 0; i < (N >> 3) + 1; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            int n = (arr[i] & maska) >> j;
            if (n == 1)
                cout << (i << 3) + j << " ";
            maska <<= 1;
        }
        maska = 1;
    }
}

void def(int n, int p)
{
    char x=127;
    char y=1;
    //cout << bitset<16>(x&~(~0<<n)<<(p+1-n)|(y&~(~0<<n))<<(p+1-n)) << endl;
    cout << bitset<8>(~0 << n);

}

int main()
{
    system("chcp 1251");
    /*
    auto start = chrono::high_resolution_clock::now();
    int size=1000,n;
    //cout << " Введите количество элементов в массиве: ";
    //cin >> size;
    unsigned char* arr = new unsigned char[N];
    create_array(arr);
    unsigned maska = 1;
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        //cin >> n;
        n = rand() % 1000;
        arr[n >> 3] = arr[n >> 3] | (maska << (n & 7));
    }
    my_sort(arr);
    auto end = chrono::high_resolution_clock::now();
    auto len = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "\nВремя выполнения: " << len.count() / 1e6 << " мс\n";
    delete[] arr;
    */
    def(2, 6);
}
