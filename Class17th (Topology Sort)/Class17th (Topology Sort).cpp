#include <iostream>

#include <queue>

#include <vector>

#define SIZE 8

using namespace std;

class Graph
{
private:
	queue<int> queue;
	vector<int> adjacencyList[SIZE];
	int degree[SIZE];
public:
	Graph()
	{
		for (int i = 0; i < SIZE;i++)
		{
			degree[i] = 0;
		}
	}
	void insert(int vertex, int edge)
	{
		adjacencyList[vertex].push_back(edge);
		degree[edge]++;
	}
	void sort()
	{
		for (int i = 1;i < SIZE; i++)
		{
			if (degree[i] == 0)
			{
				queue.push(i);
			}
		}
		while (queue.empty() == false)
		{
			int x = queue.front();
			queue.pop();
			cout << x << " ";
			for (int i = 0; i < adjacencyList[x].size();i++)
			{
				int next = adjacencyList[x][i];
				degree[next]--;
				if (degree[next] == 0)
				{
					queue.push(next);
				}
			}
		}
	}
};
int main()
{
#pragma region 위상 정렬

	//	병합 그래프에 존재하는 각 정점들의 선행 순서를 지키며,
	//	모든 정점을 차례대로 진행하는 알고리즘

	//	사이클이 발생하는 경우 위상 절렬을 수행할 수 없다.

	//	DAG(Directed Acyclic Graph) : 사이클이 존재하지 않는 그래프

	//	시간 복잡도 : O(V + E)

	// 위상 정렬 방법
	// 1. 진입 차수가 0인 정점을 Queue에 삽입
	// 2. Queue에서 원소를 꺼내 연결된 모든 간선을 제거
	// 3. 간선 제거 이후에 진입 차수가 0이 된 정점을 Queue에 삽입
	// 4. Queue가 비어있을 때까지 2~3번 작업을 반복 수행

	Graph graph;
	graph.insert(1, 2);
	graph.insert(1, 5);
	graph.insert(2, 3);
	graph.insert(3, 4);
	graph.insert(4, 6);
	graph.insert(5, 6);
	graph.insert(6, 7);
	graph.sort();
#pragma endregion

}
