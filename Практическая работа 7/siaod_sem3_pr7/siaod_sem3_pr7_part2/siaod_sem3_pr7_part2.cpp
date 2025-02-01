
#include <iostream>
#include <vector>

using namespace std;

/*
void findtreasure(vector<vector<int>>& cave, int currentroom, int currentscore, int& bestscore, vector<int>& currentpath, vector<int>& bestpath)
{
    // проверка достижения конца пещеры
    if (cave[currentroom][1] == -1 && cave[currentroom][2] == -1) {
        // сохраняем лучший счет и путь до него
        if (currentscore > bestscore) {
            bestscore = currentscore;
            bestpath = currentpath;
        }
        return;
    }

    int leftroom = cave[currentroom][1];
    int rightroom = cave[currentroom][2];

    // продолжаем поиск влево
    if (leftroom != -1) {
        currentpath.push_back(leftroom);
        findtreasure(cave, leftroom, currentscore + cave[leftroom][0], bestscore, currentpath, bestpath);
        currentpath.pop_back();  // возврат к предыдущему состоянию пути
    }

    // продолжаем поиск вправо
    if (rightroom != -1) {
        currentpath.push_back(rightroom);
        findtreasure(cave, rightroom, currentscore + cave[rightroom][0], bestscore, currentpath, bestpath);
        currentpath.pop_back();  // возврат к предыдущему состоянию пути
    }
}

// функция для поиска сокровища в пещере
void searchtreasure(vector<vector<int>>& cave) {
    int n = cave.size(); // общее количество комнат в пещере

    if (n == 0) {
        cout << "Пещера пуста." << endl;
        return;
    }

    int currentscore = 0; // текущий счет очков
    int bestscore = 0; // лучший счет очков
    vector<int> currentpath;  // текущий путь до лучшего результата
    vector<int> bestpath;  // лучший путь до лучшего результата

    // начинаем поиск с комнаты 0 (вход в пещеру)
    currentpath.push_back(0);
    findtreasure(cave, 0, currentscore, bestscore, currentpath, bestpath);

    // выводим лучший результат и путь до него
    cout << "Лучший счет очков: " << bestscore << endl;
    cout << "Лучший путь: ";
    for (int i = 0; i < bestpath.size(); i++) {
        if (i > 0) {
            cout << " -> ";
        }
        cout << bestpath[i];
    }
    cout << endl;
}

*/


/*
// функция для получения максимально возможного количества очков в пещере, начиная с указанной комнаты
int getmaxpossiblescore(vector<vector<int>>& cave, int currentroom) {
    if (currentroom == -1) {
        return 0;
    }

    int leftroom = cave[currentroom][1];
    int rightroom = cave[currentroom][2];

    int leftscore = getmaxpossiblescore(cave, leftroom);
    int rightscore = getmaxpossiblescore(cave, rightroom);

    return cave[currentroom][0] + max(leftscore, rightscore);
}

void findtreasure(vector<vector<int>>& cave, int currentroom, int currentscore, int& bestscore, vector<int>& currentpath, vector<int>& bestpath)
{
    // проверка достижения конца пещеры
    if (cave[currentroom][1] == -1 && cave[currentroom][2] == -1) {
        // сохраняем лучший счет и путь до него
        if (currentscore >= bestscore) {
            bestscore = currentscore;
            bestpath = currentpath;
        }
        return;
    }

    int leftroom = cave[currentroom][1];
    int rightroom = cave[currentroom][2];

    // продолжаем поиск только если текущий счет + максимально возможный остаток очков превышает лучший счет
    if (currentscore + getmaxpossiblescore(cave, currentroom) <= bestscore) {
        return;
    }

    // продолжаем поиск влево
    if (leftroom != -1) {
        currentpath.push_back(leftroom);
        findtreasure(cave, leftroom, currentscore + cave[leftroom][0], bestscore, currentpath, bestpath);
        currentpath.pop_back();  // возврат к предыдущему состоянию пути
    }

    // продолжаем поиск вправо
    if (rightroom != -1) {
        currentpath.push_back(rightroom);
        findtreasure(cave, rightroom, currentscore + cave[rightroom][0], bestscore, currentpath, bestpath);
        currentpath.pop_back();  // возврат к предыдущему состоянию пути
    }
}

// функция для поиска сокровища в пещере
void searchtreasure(vector<vector<int>>& cave) {
    int currentscore = cave[0][0]; // текущий счет очков
    int bestscore = INT_MIN; // лучший счет очков
    vector<int> currentpath;  // текущий путь до лучшего результата
    vector<int> bestpath;  // лучший путь до лучшего результата

    // начинаем поиск с комнаты 0 (вход в пещеру)
    currentpath.push_back(0);
    findtreasure(cave, 0, currentscore, bestscore, currentpath, bestpath);

    // выводим лучший результат и путь до него
    cout << "лучший счет очков: " << bestscore << endl;
    cout << "лучший путь: ";
    for (int i = 0; i < bestpath.size(); i++) {
        if (i > 0) {
            cout << " -> ";
        }
        cout << bestpath[i];
    }
    cout << endl;
}

*/

void findtreasure(vector<vector<int>>& cave, int currentroom, int currentscore, int& bestscore, vector<int>& currentpath, vector<int>& bestpath, int depth)
{
    // проверка достижения конца пещеры
    if (cave[currentroom][1] == -1 && cave[currentroom][2] == -1) {
        // сохраняем лучший счет и путь до него
        if (currentscore >= bestscore) {
            bestscore = currentscore;
            bestpath = currentpath;
        }
        return;
    }

    int leftroom = cave[currentroom][1];
    int rightroom = cave[currentroom][2];

    // максимальное количество очков, которое можно получить на текущем уровне
    int maxPossibleScore = pow(2, depth - currentpath.size());

    // продолжаем поиск только если текущий счет + максимально возможный остаток очков превышает лучший счет
    if (currentscore + maxPossibleScore <= bestscore) {
        return;
    }

    // продолжаем поиск влево
    if (leftroom != -1) {
        currentpath.push_back(leftroom);
        findtreasure(cave, leftroom, currentscore + cave[leftroom][0], bestscore, currentpath, bestpath, depth);
        currentpath.pop_back();  // возврат к предыдущему состоянию пути
    }

    // продолжаем поиск вправо
    if (rightroom != -1) {
        currentpath.push_back(rightroom);
        findtreasure(cave, rightroom, currentscore + cave[rightroom][0], bestscore, currentpath, bestpath, depth);
        currentpath.pop_back();  // возврат к предыдущему состоянию пути
    }
}

// функция для поиска сокровища в пещере
void searchtreasure(vector<vector<int>>& cave) {
    int currentscore = cave[0][0]; // текущий счет очков
    int bestscore = INT_MIN; // лучший счет очков
    vector<int> currentpath;  // текущий путь до лучшего результата
    vector<int> bestpath;  // лучший путь до лучшего результата

    // вычисляем глубину дерева
    int depth = log2(cave.size());

    // начинаем поиск с комнаты 0 (вход в пещеру)
    currentpath.push_back(0);
    findtreasure(cave, 0, currentscore, bestscore, currentpath, bestpath, depth);

    // выводим лучший результат и путь до него
    cout << " Лучший счет очков: " << bestscore << endl;
    cout << " Лучший путь: ";
    for (int i = 0; i < bestpath.size(); i++) {
        if (i > 0) {
            cout << " -> ";
        }
        cout << bestpath[i];
    }
    cout << endl;
}

int main()
{
    system("chcp 1251");
    int n, num, res, room1, room2,points;
    vector<vector<int>> cave;
    while (true)
    {
        cout << "-----------------------------------------------------------------------------------------------------------" << endl;
        cout << " Меню\n";
        cout << " 1. Заполнить пещеру с клавиатуры\n";
        cout << " 2. Заполнить пещеру с клавиатуры со случайным количеством очков в комнатах\n";
        cout << " 3. Собрать максимальное количество сокровищ в пещере\n";
        cout << " 4. Протестировать функцию на готовом векторе\n";
        cout << " 5. Завершить выполнение программы\n";
        cin >> num;
        switch (num)
        {
        case 1:
        {
            cave.clear();
            cout << " Введите количесто комнат: ";
            cin >> n;
            if (n == 0)
                cout << " Пустая пещера\n";
            else if (n==1)
                cave.push_back({ 0,-1,-1 });
            else
            {
                cout << "!!!!! Введите -1 в переходе в левую и правую комнату, если текущая комната - конец пещеры !!!!!\n";
                for (int i = 0; i < n; i++)
                {
                    if (i == 0)
                    {
                        cout << " Введите в какую комнату налево можно перейти из начальной комнаты: ";
                        cin >> room1;
                        while (room1 > n-1 or room1 == i)
                        {
                            cout << " Введено неверное значение для левой комнаты, попробуйте еще раз: ";
                            cin >> room1;
                        }
                        cout << " Введите в какую комнату направо можно перейти из начальной комнаты: ";
                        cin >> room2;
                        while (room2 > n-1 or room2 == i)
                        {
                            cout << " Введено неверное значение для правой комнаты, попробуйте еще раз: ";
                            cin >> room2;
                        }
                        if (room2 == room1 and room2 != -1)
                        {
                            while (room2 == room1)
                            {
                                cout << " Нельзя перейти в одну и ту же комнату, идя налево и направо, попробуйте еще раз: ";
                                cin >> room2;
                            }
                        }
                        cave.push_back({0,room1,room2});
                    }
                    else
                    {
                        cout << " Введите в какую комнату налево можно перейти из " << i <<  " комнаты: ";
                        cin >> room1;
                        while (room1 > n - 1 or room1 == i)
                        {
                            cout << " Введено неверное значение для левой комнаты, попробуйте еще раз:";
                            cin >> room1;
                        }
                        cout << " Введите в какую комнату направо можно перейти из " << i << " комнаты: ";
                        cin >> room2;
                        while (room2 > n - 1 or room2 == i)
                        {
                            cout << " Введено неверное значение для правой комнаты, попробуйте еще раз: ";
                            cin >> room2;
                        }
                        if (room2 == room1 and room2 != -1)
                        {
                            while (room2 == room1)
                            {
                                cout << " Нельзя перейти в одну и ту же комнату, идя налево и направо, попробуйте еще раз: ";
                                cin >> room2;
                            }
                        }
                        cout << " Введите количество очков в комнате " << i << " (-1 или 1): ";
                        cin >> points;
                        while (points != 1 && points != -1)
                        {
                            cout << " Неверное значение для количества очков в комнате, попробуйте еще раз: ";
                            cin >> points;
                        }
                        cave.push_back({ points,room1,room2 });
                    }
                }
            }
            break;
        }
        case 2:
        {
            cave.clear();
            cout << " Введите количесто комнат: ";
            cin >> n;
            if (n == 0)
                cout << " Пустая пещера\n";
            else if (n == 1)
                cave.push_back({ 0,-1,-1 });
            else
            {
                cout << "!!!!! Введите -1 в переходе в левую и правую комнату, если текущая комната - конец пещеры !!!!!\n";
                for (int i = 0; i < n; i++)
                {
                    if (i == 0)
                    {
                        cout << " Введите в какую комнату налево можно перейти из начальной комнаты: ";
                        cin >> room1;
                        while (room1 > n - 1 or room1 == i)
                        {
                            cout << " Введено неверное значение для левой комнаты, попробуйте еще раз:";
                            cin >> room1;
                        }
                        cout << " Введите в какую комнату направо можно перейти из начальной комнаты: ";
                        cin >> room2;
                        while (room2 > n - 1 or room2 == i)
                        {
                            cout << " Введено неверное значение для правой комнаты, попробуйте еще раз: ";
                            cin >> room2;
                        }
                        if (room2 == room1 and room2 != -1)
                        {
                            while (room2 == room1)
                            {
                                cout << " Нельзя перейти в одну и ту же комнату, идя налево и направо, попробуйте еще раз: ";
                                cin >> room2;
                            }
                        }
                        cave.push_back({ 0,room1,room2 });
                    }
                    else
                    {
                        cout << " Введите в какую комнату налево можно перейти из " << i << " комнаты: ";
                        cin >> room1;
                        while (room1 > n - 1 or room1 == i)
                        {
                            cout << " Введено неверное значение для левой комнаты, попробуйте еще раз:";
                            cin >> room1;
                        }
                        cout << " Введите в какую комнату направо можно перейти из " << i << " комнаты: ";
                        cin >> room2;
                        while (room2 > n - 1 or room2 == i)
                        {
                            cout << " Введено неверное значение для правой комнаты, попробуйте еще раз: ";
                            cin >> room2;
                        }
                        if (room2 == room1 and room2 != -1)
                        {
                            while (room2 == room1)
                            {
                                cout << " Нельзя перейти в одну и ту же комнату, идя налево и направо, попробуйте еще раз: ";
                                cin >> room2;
                            }
                        }
                        cave.push_back({ (rand()%2)*2-1,room1,room2});
                    }
                }
            }
            break;
        }
        case 3:
        {
            if (cave.size() == 0)
                cout << " Пустая пещера\n";
            else
                searchtreasure(cave);
            break;
        }
        case 4:
        {
            cave = {
                {0, 1, 2}, //0
                {1, 3, 4}, //1
                {1, 5, 6}, //2
                {-1, 7, 8}, //3
                {1, 9, 10}, //4
                {-1, 11, 12}, //5
                {1, 13, 14}, //6
                {1, 15, 16}, //7
                {1, 17, 18}, //8
                {-1, 19, 20}, //9
                {-1, 21, 22}, //10
                {1, 23, 24}, //11
                {1, 25, 26}, //12
                {1, 27, 28}, //13
                {1, 29, 30}, //14
                {-1, -1, -1}, //15
                {-1, -1, -1}, //16
                {-1, -1, -1}, //17
                {-1, -1, -1}, //18
                {-1, -1, -1}, //19
                {-1, -1, -1}, //20
                {-1, 31, -1}, //21
                {-1, -1, -1}, //22
                {1, -1, -1}, //23
                {1, -1, -1}, //24
                {-1, -1, -1}, //25
                {1, -1, -1}, //26
                {-1, -1, -1}, //27
                {1, -1, -1}, //28
                {-1, -1, -1}, //29
                {-1, -1, -1}, //30
                {-1, -1, -1}, //31

            };
            searchtreasure(cave);
            break;
        }
        case 5:
            return 0;
        default:
        {
            cout << " Нет такого пункта\n";
        }
        }
    }
}