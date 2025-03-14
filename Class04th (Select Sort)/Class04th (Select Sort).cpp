#include <iostream>

#define SIZE 5

using namespace std;

int main()
{
#pragma region 선택 정렬

	//	주어진 리스트 중에 최소값을 찾은 다음 특정한 위치에서 결과를 교체하는 방식으로 정렬하는 알고리즘

	int array[SIZE] = { 6,2,8,1,0 };
	int index = 0;
	int count = 0;

	while (count < SIZE)
	{
		for (int i = count; i < SIZE - 1; i++)
		{
			if (array[index] < array[i + 1])
			{
				index = i;
			}
			else if (array[index] > array[i + 1])
			{
				index = i + 1;
			}
		}
		std:swap(array[count++], array[index]);
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << array[i] << " ";
	}
#pragma endregion

}
