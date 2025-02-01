#include "Graph.h"
Edge EDGE(int v, int w, Edge e)
{
	e.v = v;
	e.w = w;
	return e;
}

void GRAPHInit(int V, Graph& G)
{
	G.V = V;//инициализация значения V
	G.E = 0;//инициализация значения Е
	//Создание двумерного массива (матрицы) размером V*V
	G.Matr = new int* [V];
	for (int v = 0; v < V; v++)
		G.Matr[v] = new int[V];
	//заполнение элементов матрицы значением 0
	for (int v = 0; v < V; v++)
		for (int w = 0; w < V; w++)
		{
			G.Matr[v][w] = 0;
		}
}

//Предусловие: на вход поступает граф G и данные вставляемого ребра e/
//Постусловие: вставка ребра в матрицу смежности неориентированного графа
void GRAPHInsert(Graph& G, Edge e)
{
	int v = e.v-1, w = e.w-1;
	if (G.Matr[v][w] == 0)
	{
		G.E++;//подсчет количества вставленных ребер
		G.Matr[v][w] = e.info;
		G.Matr[w][v] = e.info;
	}
}

bool printGraphMatrix(Graph G)
{
	if (G.V == 0)
		return 1;
	for (int i = 0; i < G.V; i++)
	{
		for (int j = 0; j < G.V; j++)
		{
			cout << G.Matr[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

bool printGraph(Graph G)
{
	if (G.V == 0)
		return 1;
	bool flag = 0;
	for (int i = 0; i < G.V; i++)
	{
		flag = 0;
		cout << " " << i + 1 << ": [";
		for (int j = 0; j < G.V; j++)
		{
			if (G.Matr[i][j] != 0)
			{
				if (not flag)
				{
					cout << j + 1 << "(" << G.Matr[i][j] << ")";
					flag = 1;
				}
				else
				{
					cout << ", " << j+1 << "(" << G.Matr[i][j] << ")";
				}
			}
		}
		cout << ']'<<'\n';
	}
	return 0;
}

int dfs(Graph G, int v, int* visited)
{
	int maxDepth = 0;
	visited[v] = 1;
	for (int w = 0; w < G.V; w++)
	{
		if (G.Matr[v][w] != 0 && visited[w] == 0)
		{
			int depth = dfs(G, w, visited) + G.Matr[v][w];
			if (depth > maxDepth)
				maxDepth = depth;
		}
	}
	visited[v] = 0;
	return maxDepth;
}

int maindfs(Graph G, int v)
{
	int* visited = new int[G.V];
	for (int v1 = 0; v1 < G.V; v1++)
		visited[v1] = 0;
	int depth = dfs(G, v, visited);
	delete[] visited;
	return depth;
}

void buildSpanningTree(Graph& G, Graph& T, int start)
{
	T.V = G.V; // Количество вершин в остовном дереве равно количеству вершин в графе
	T.E = 0; // Количество ребер в остовном дереве инициализируем нулем
	T.Matr = new int* [T.V]; // Создаем матрицу смежности для остовного дерева
	for (int i = 0; i < T.V; i++)
	{
		T.Matr[i] = new int[T.V];
		for (int j = 0; j < T.V; j++)
			T.Matr[i][j] = 0;
	}

	std::queue<int> queue; // Очередь для обхода в ширину
	std::vector<bool> visited(T.V, false); // Вектор для отслеживания посещенных вершин
	visited[start] = true; // Помечаем стартовую вершину как посещенную
	queue.push(start); // Добавляем стартовую вершину в очередь

	while (!queue.empty())
	{
		int v = queue.front(); // Берем вершину из начала очереди
		queue.pop(); // Удаляем вершину из очереди

		for (int w = 0; w < T.V; w++)
		{
			if (G.Matr[v][w] != 0 && !visited[w]) // Если есть ребро из текущей вершины в смежную непосещенную вершину
			{
				T.Matr[v][w] = G.Matr[v][w]; // Добавляем ребро в остовное дерево
				T.Matr[w][v] = G.Matr[v][w];
				T.E++; // Увеличиваем количество ребер в остовном дереве
				visited[w] = true; // Помечаем смежную вершину как посещенную
				queue.push(w); // Добавляем смежную вершину в очередь
			}
		}
	}
}

void printSpanningTree(Graph T)
{
	for (int i = 0; i < T.V; i++)
	{
		for (int j = 0; j < T.V; j++)
		{
			if (T.Matr[i][j] != 0)
			{
				cout << i + 1 << " -> " << j + 1 << " (" << T.Matr[i][j] << ")" << '\n';
			}
		}
	}
}

void colorGraph(Graph& G) {
	int n = G.V; // Количество вершин
	int** A = G.Matr; // Матрица смежности

	set<int> V; // Множество вершин
	for (int i = 0; i < n; i++) {
		V.insert(i);
	}

	int k = 1; // Цвет
	set<int> Sk; // Независимое множество покрашенных вершин

	for (int i = 0; i < n; i++) {
		if (V.find(i) == V.end()) { // Вершина уже покрашена, переходим к следующей
			continue;
		}

		Sk.insert(i); // Красим текущую вершину
		V.erase(i);

		while (true) {
			int j = i + 1;
			while (j < n && (A[i][j] == 1 || V.find(j) == V.end())) {
				j++;
			}

			if (j == n) {
				break;
			}

			Sk.insert(j); // Красим соседнюю вершину
			V.erase(j);

			// Обновление строки i матрицы A
			for (int l = 0; l < n; l++) {
				A[i][l] |= A[j][l];
			}
		}

		// Вывод информации о текущей цветовой группе
		cout << "Color " << k << ": ";
		for (int v : Sk) {
			cout << v+1 << " ";
		}
		cout << endl;
		k++;
		Sk.clear();
	}
}