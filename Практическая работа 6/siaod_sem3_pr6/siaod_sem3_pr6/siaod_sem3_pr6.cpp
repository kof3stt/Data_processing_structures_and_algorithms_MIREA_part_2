#include "Graph.h"

int main()
{
	system("chcp 1251");
	Graph graph,T;
	int num,V,deep,maxDeep=0;
	bool res;
	while (true)
	{
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;
		cout << " Меню\n";
		cout << " 1. Заполнить граф с клавиатуры\n";
		cout << " 2. Вывести матрицу смежности графа на экран\n";
		cout << " 3. Вывести граф в виде списка смежных вершин\n";
		cout << " 4. Определить глубину графа\n";
		cout << " 5. Построить остовное дерево методом поиска в ширину. Вывести дерево на экран\n";
		cout << " 6. Раскрасить граф\n";
		cout << " 7. Завершить выполнение программы\n";
		cin >> num;
		switch (num)
		{
		case 1:
		{
			cout << " Введите количество вершин в графе: ";
			cin >> V;
			if (V == 0)
				cout << " Задан пустой граф\n";
			else
			{
				GRAPHInit(V, graph);
				while (true)
				{
					Edge e;
					cout << " Введите номера вершин ребра (от 1 до " << graph.V << "):\n";
					cout << " Вершина-исток: ";
					cin >> e.v;
					cout << " Вершина-сток: ";
					cin >> e.w;
					cout << " Введите вес вершины: ";
					cin >> e.info;
					if (e.w > graph.V or e.w < 1 or e.v<1 or e.v>graph.V)
						cout << " Неккоректые номера вершин, повторите ввод\n";
					else if (e.w == e.v)
						cout << " Граф не должен иметь рёбра, исходящие из вершины и входящие в неё\n";
					else
						GRAPHInsert(graph, e);
					cout << " Продолжить? 1 - да, 0 - нет\n";
					cin >> num;
					if (num == 0)
						break;
				}
			}
			break;
		}
		case 2:
		{
			cout << " Матрица смежности графа:\n";
			res = printGraphMatrix(graph);
			if (res)
				cout << " Пустой граф\n";
			break;
		}
		case 3:
		{
			cout << " Граф в виде списка смежных вершин (в скобках указан вес вершины):\n";
			res = printGraph(graph);
			if (res)
				cout << " Пустой граф\n";
			break;
		}
		case 4:
		{
			if (graph.V == 0)
				cout << " Пустой граф\n";
			else
			{
				maxDeep = 0;
				for (int i = 0; i < graph.V; i++)
				{
					deep = maindfs(graph, i);
					cout << " Глубина графа от вершины " << i+1 << ": " << deep << endl;
					maxDeep = max(deep, maxDeep);
				}
				cout << " Глубина графа: " << maxDeep << endl;
			}
			break;
		}
		case 5:
			if (graph.V == 0)
				cout << " Пустой граф\n";
			else
			{
				buildSpanningTree(graph, T, 1); // Строим остовное дерево методом поиска в ширину
				printSpanningTree(T);
			}
			break;
		case 6:
			if (graph.V == 0)
				cout << " Пустой граф\n";
			else
			{
				colorGraph(graph);
			}
			break;
		case 7:
			return 0;
		default:
		{
			cout << " Нет такого пункта\n";
		}
		}
	}
}