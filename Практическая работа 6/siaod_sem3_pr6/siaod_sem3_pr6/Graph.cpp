#include "Graph.h"
Edge EDGE(int v, int w, Edge e)
{
	e.v = v;
	e.w = w;
	return e;
}

void GRAPHInit(int V, Graph& G)
{
	G.V = V;//������������� �������� V
	G.E = 0;//������������� �������� �
	//�������� ���������� ������� (�������) �������� V*V
	G.Matr = new int* [V];
	for (int v = 0; v < V; v++)
		G.Matr[v] = new int[V];
	//���������� ��������� ������� ��������� 0
	for (int v = 0; v < V; v++)
		for (int w = 0; w < V; w++)
		{
			G.Matr[v][w] = 0;
		}
}

//�����������: �� ���� ��������� ���� G � ������ ������������ ����� e/
//�����������: ������� ����� � ������� ��������� ������������������ �����
void GRAPHInsert(Graph& G, Edge e)
{
	int v = e.v-1, w = e.w-1;
	if (G.Matr[v][w] == 0)
	{
		G.E++;//������� ���������� ����������� �����
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
	T.V = G.V; // ���������� ������ � �������� ������ ����� ���������� ������ � �����
	T.E = 0; // ���������� ����� � �������� ������ �������������� �����
	T.Matr = new int* [T.V]; // ������� ������� ��������� ��� ��������� ������
	for (int i = 0; i < T.V; i++)
	{
		T.Matr[i] = new int[T.V];
		for (int j = 0; j < T.V; j++)
			T.Matr[i][j] = 0;
	}

	std::queue<int> queue; // ������� ��� ������ � ������
	std::vector<bool> visited(T.V, false); // ������ ��� ������������ ���������� ������
	visited[start] = true; // �������� ��������� ������� ��� ����������
	queue.push(start); // ��������� ��������� ������� � �������

	while (!queue.empty())
	{
		int v = queue.front(); // ����� ������� �� ������ �������
		queue.pop(); // ������� ������� �� �������

		for (int w = 0; w < T.V; w++)
		{
			if (G.Matr[v][w] != 0 && !visited[w]) // ���� ���� ����� �� ������� ������� � ������� ������������ �������
			{
				T.Matr[v][w] = G.Matr[v][w]; // ��������� ����� � �������� ������
				T.Matr[w][v] = G.Matr[v][w];
				T.E++; // ����������� ���������� ����� � �������� ������
				visited[w] = true; // �������� ������� ������� ��� ����������
				queue.push(w); // ��������� ������� ������� � �������
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
	int n = G.V; // ���������� ������
	int** A = G.Matr; // ������� ���������

	set<int> V; // ��������� ������
	for (int i = 0; i < n; i++) {
		V.insert(i);
	}

	int k = 1; // ����
	set<int> Sk; // ����������� ��������� ����������� ������

	for (int i = 0; i < n; i++) {
		if (V.find(i) == V.end()) { // ������� ��� ���������, ��������� � ���������
			continue;
		}

		Sk.insert(i); // ������ ������� �������
		V.erase(i);

		while (true) {
			int j = i + 1;
			while (j < n && (A[i][j] == 1 || V.find(j) == V.end())) {
				j++;
			}

			if (j == n) {
				break;
			}

			Sk.insert(j); // ������ �������� �������
			V.erase(j);

			// ���������� ������ i ������� A
			for (int l = 0; l < n; l++) {
				A[i][l] |= A[j][l];
			}
		}

		// ����� ���������� � ������� �������� ������
		cout << "Color " << k << ": ";
		for (int v : Sk) {
			cout << v+1 << " ";
		}
		cout << endl;
		k++;
		Sk.clear();
	}
}