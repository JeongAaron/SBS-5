#include <iostream>

#define SIZE 8

using namespace std;

void binary_search(int list[], int key)
{
	int left = 0;
	int right = SIZE - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (list[mid] == key)
		{
			cout << "Key index: " << mid << endl;
			return;
		}
		else if (list[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	cout << "Not key found" << endl;
}
int main()
{
#pragma region 이진 탐색

	//	탐색 범위를 반으로 나누어 찾는 값을 포함하는 범위를
	//	좁혀나가는 방식으로 동작하는 알고리즘

	int list[SIZE] = { 5,66,27,13,11,55,6,99 };
	int count = 0;
	while (count < SIZE)
	{
		for (int i = 0; i < SIZE - 1; i++)
		{
			if (list[i] > list[i + 1])
			{
			std:swap(list[i], list[i + 1]);
			}
		}
		count++;
	}
	binary_search(list, 0);
#pragma endregion
}
