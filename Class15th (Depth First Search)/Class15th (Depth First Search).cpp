#include <iostream>

#include <vector>

#define SIZE 8

using namespace std;

class Node
{
private:
	bool visited[SIZE];
	vector<int> adjacencyList[SIZE];
public:
	Node()
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
		}
	}
	void insert(int i, int j)
	{
		adjacencyList[i].push_back(j);
		adjacencyList[j].push_back(i);
	}
	void search(int start)
	{
		visited[start] = true;
		cout << start << " ";
		for (int i = 0; i < adjacencyList[start].size();i++)
		{
			int next = adjacencyList[start][i];
			if (visited[next] == false)
			{
				search(next);
			}
		}
	}
};
int main()
{

#pragma region 깊이 우선 탐색(Depth First Search)

	//	root 노트에서부터 다음 분기로 넘어가기 전에 해당 분기를 완벽하게 탐색하는 방법

	//	깊이 우선 탐색은 스택을 활용

	//	1. 시작 노드를 스택에 넣고 방문 처리를 한다.

	//	2. 스택의 최상단 노드에 방문하지 않은 인접 노드가 있으면 그 노드를 스택에 넣고 방문 처리

	//	3. 방문하지 않은 인접 노드가 없으면 스택에서 최상단에 있는 노드를 꺼낸다.

	//	4. 더 이상 2번의 과정을 수행할 수 없을 때까지 반복

	Node graph;
	graph.insert(1, 2);
	graph.insert(1, 3);
	graph.insert(2, 3);
	graph.insert(2, 4);
	graph.insert(2, 5);
	graph.insert(3, 6);
	graph.insert(3, 7);
	graph.insert(4, 5);
	graph.insert(6, 7);
	graph.search(1);
#pragma endregion

}
