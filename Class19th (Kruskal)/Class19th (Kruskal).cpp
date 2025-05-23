﻿#include <iostream>

#include <vector>

#include <algorithm>

#define SIZE 8

using namespace std;

class Kruskal
{
private:
	class Edge
	{
	private:
		int vertexX, vertexY, weight;
	public:
		Edge(int vertexX, int vertexY, int weight)
		{
			this->vertexX = vertexX;
			this->vertexY = vertexY;
			this->weight = weight;
		}
		const bool& operator<(const Edge& edge)
		{
			return weight < edge.weight;
		}
		const int& VertexX() { return vertexX; }
		const int& VertexY() { return vertexY; }
		const int& Weight() { return weight; }
	};
	int cost;
	int parent[SIZE];
	vector<Edge> nodeList;
public:
	Kruskal()
	{
		cost = 0;
		for (int i = 0;i < SIZE;i++)
		{
			parent[i] = i;
		}
	}
	void insert(int x, int y, int z)
	{
		nodeList.push_back(Edge(x, y, z));
	}
	int find(int x)
	{
		if (x == parent[x])
		{
			return x;
		}
		else
		{
			return parent[x] = find(parent[x]);
		}
	}
	void Union(int x, int y)
	{
		x = find(x);
		y = find(y);
		if (x == y)
		{
			return;
		}
		if (x < y)
		{
			parent[y] = x;
		}
		else
		{
			parent[x] = y;
		}
	}
	bool same(int x, int y)
	{
		return find(x) == find(y);
	}
	void calculate()
	{
		sort(nodeList.begin(), nodeList.end());
		for (int i = 0; i < nodeList.size();i++)
		{
			if (same(nodeList[i].VertexX(), nodeList[i].VertexY()) == false)
			{
				cost += nodeList[i].Weight();
				Union(nodeList[i].VertexX(), nodeList[i].VertexY());
			}
		}
		cout << "Cost : " << cost << endl;
	}
};
int main()
{
#pragma region 최소 신장 트리

	//	그래프의 모든 정점을 포함하면서 사이클이 존재하지 않는 부분 그래프로,
	//	그래프의 모든 정점을 최소 비용으로 연결하는 트리

	//	그래프의 정점의 수가 n개일 때, 간선의 수는 n-1개

	Kruskal kruskal;
	kruskal.insert(1, 2, 64);
	kruskal.insert(1, 4, 30);
	kruskal.insert(1, 5, 19);
	kruskal.insert(1, 7, 10);
	kruskal.insert(2, 4, 25);
	kruskal.insert(2, 5, 61);
	kruskal.insert(3, 5, 22);
	kruskal.insert(3, 6, 36);
	kruskal.insert(4, 7, 14);
	kruskal.insert(5, 6, 48);
	kruskal.insert(5, 7, 73);
	kruskal.calculate();

#pragma endregion
}
