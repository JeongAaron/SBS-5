#include <iostream>

#define SIZE 6

#define INFINITY 10000000

using namespace std;

class Dijkstra
{
private:
	int adjacencyList[SIZE][SIZE];
	int distance[SIZE];
	bool visited[SIZE];
public:
	Dijkstra()
	{
		for (int i = 0; i < SIZE;i++)
		{
			for (int j = 0; j < SIZE;j++)
			{
				adjacencyList[i][j] = 0;
				visited[j] = false;
				distance[j] = 0;
			}
		}
	}
	void insert(int x, int y, int z)
	{
		if (x > 0 && y > 0)
		{
			adjacencyList[x - 1][y - 1] = z;
			adjacencyList[y - 1][x - 1] = z;
		}
		else
		{
			cout << "Out of bounds of the 2D array" << endl;
		}
	}
	void print()
	{
		for (int i = 0; i < SIZE;i++)
		{
			for (int j = 0; j < SIZE; j++)
			{
				if (adjacencyList[i][j] != INFINITY)
				{
					cout << " " << adjacencyList[i][j] << "│";
				}
				else
				{
					cout << "∞" << "│";
				}
			}
			cout << endl;
			cout << "─────────────────" << endl;
		}
	}
	const int& Find()
	{
		int index = 0;
		int min = INFINITY;
		for (int i = 0; i < SIZE;i++)
		{
			if (distance[i] < min && visited[i] == false)
			{
				min = distance[i];
				index = i;
			}
		}
		return index;
	}
	void calculate(int start)
	{
		for (int i = 0; i < SIZE;i++)
		{
			distance[i] = adjacencyList[start][i];
		}
		visited[start] = true;
		for (int i = 0;i < SIZE - 1;i++)
		{
			int x = Find();
			visited[x] = true;
			for (int j = 0;j < SIZE;j++)
			{
				if (visited[j] == false)
				{
					if (distance[x] + adjacencyList[x][j] < distance[j])
					{
						distance[j] = distance[x] + adjacencyList[x][j];
					}
				}
			}
		}
		for (int i = 0; i < SIZE;i++)
		{
			cout << distance[i] << " ";
		}
	}
};

int main()
{
#pragma region 다익스트라 알고리즘

	//	시작점으로부터 모든 노드까지의 최소 거리를 구해주는 알고리즘

	//	1. 거리 배열에 weight[시작 노드]의 값들로 초기화
	//	2. 시작점을 방문 처리
	//	3. 거리 배열에서 최소 비용 노드를 찾고 방문처리
	//	   단, 이미 방문한 노드는 제외
	//	4. 최소 비용 노드를 거쳐갈 지 고민해서 거리 배열을 갱신
	//	   단, 이미 방문한 노드는 제외
	//	5. 모든 노드를 방문할 때까지 3~4번 반복

	//	방문하지 않은 노드 중에서 가장 작은 거리를 가진 노드를 방문하고,
	//	그 노드와 연결된 다른 노드까지의 거기를 계산

	Dijkstra dijkstra;
	dijkstra.insert(1, 1, 0);
	dijkstra.insert(1, 2, 2);
	dijkstra.insert(1, 3, 5);
	dijkstra.insert(1, 4, 1);
	dijkstra.insert(1, 5, INFINITY);
	dijkstra.insert(1, 6, INFINITY);
	dijkstra.insert(2, 2, 0);
	dijkstra.insert(2, 3, 3);
	dijkstra.insert(2, 4, 2);
	dijkstra.insert(2, 5, INFINITY);
	dijkstra.insert(2, 6, INFINITY);
	dijkstra.insert(3, 3, 0);
	dijkstra.insert(3, 4, 3);
	dijkstra.insert(3, 5, 1);
	dijkstra.insert(3, 6, 5);
	dijkstra.insert(4, 4, 0);
	dijkstra.insert(4, 5, 1);
	dijkstra.insert(4, 6, INFINITY);
	dijkstra.insert(5, 5, 0);
	dijkstra.insert(5, 6, 2);
	dijkstra.insert(6, 6, 0);
	dijkstra.calculate(0);

#pragma endregion
}
