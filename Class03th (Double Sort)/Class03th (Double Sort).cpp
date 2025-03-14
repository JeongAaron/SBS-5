#include <iostream>

#define SIZE 5

using namespace std;

int main()
{
#pragma region 거품 정렬

	//	서로 인접한 두 원소를 비교하여 정렬하는 알고리즘

	int array[SIZE] = { 13,8,97,1,36 };
	int count = 0;
	while (count < SIZE)
	{
		for (int i = 0; i < SIZE - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
			std:swap(array[i], array[i + 1]);
			}
		}
		count++;
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << array[i] << " ";
	}
#pragma endregion

}
