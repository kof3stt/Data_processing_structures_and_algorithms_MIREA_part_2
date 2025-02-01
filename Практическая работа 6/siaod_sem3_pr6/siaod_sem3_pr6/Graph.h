#pragma once
#include <iostream>
#include <queue>
#include<set>
using namespace std;

struct Edge //��������� �����
{
	// v � w ��� ������ ������ �����
	int v; // �����
	int w; // ����
	int info;
};

Edge EDGE(int v, int w, Edge e);


//��������� ������������� ����� �� ������� ���������
struct Graph
{
    int V; // ���������� ������
    int E; // ���������� �����
    int** Matr; // ������� ���������
    Graph(int V) : V(V), E(0) // �������� ����������� ��� ��������� �������� V
    {
        Matr = new int* [V];
        for (int i = 0; i < V; i++)
        {
            Matr[i] = new int[V];
            for (int j = 0; j < V; j++)
                Matr[i][j] = 0;
        }
    }
    Graph() {V = 0; }
};

void GRAPHInit(int V, Graph& G);
void GRAPHInsert(Graph& G, Edge e);
bool printGraphMatrix(Graph G);
bool printGraph(Graph G);
int dfs(Graph G, int v, int* visited);
int maindfs(Graph G, int v);
void buildSpanningTree(Graph& G, Graph& T, int start);
void printSpanningTree(Graph T);
void colorGraph(Graph& G);