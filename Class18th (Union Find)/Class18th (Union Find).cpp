#include <iostream>

#define SIZE 6

int list[SIZE];

using namespace std;

int find(int x)
{
	if (x == list[x])
	{
		return x;
	}
	else
	{
		return list[x] = find(list[x]);
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
		list[y] = x;
	}
	else
	{
		list[x] = y;
	}
}

bool same(int x, int y)
{
	return find(x) == find(y);
}

int main()
{
#pragma region 유니온 파인드

	//	여러 노드가 존재할 때 어떤 노드가 다른 노드와 연결되어 있는 지
	//	확인하는 알고리즘

	//	Union : 특정한 두 개의 노드를 같은 집합으로 합치는 연산

	//	Find : 특정한 노드가 어느 집합에 있었는 지 확인하는 연산

	for (int i = 0; i < SIZE; i++)
	{
		list[i] = i;
	}
	Union(0, 1);
	Union(3, 4);
	Union(4, 5);

	for (int i = 0; i < SIZE - 1; i++)
	{
		cout << same(i, i + 1) << " ";
	}

#pragma endregion

}
