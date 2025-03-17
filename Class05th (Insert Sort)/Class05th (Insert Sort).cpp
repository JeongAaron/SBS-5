#include <iostream>

#define SIZE 5

using namespace std;

int main()
{
#pragma region 삽입 정렬

	//	데이터를 하나씩 확인하면서 이미 정렬된 부분과 비교하여 자신의 위치를 찾아 삽입하여 정렬하는 알고리즘

	int array[SIZE] = { 9,6,8,1,3 };
	int key = 0;
	for (int i = 0; i < SIZE - 1; i++)
	{
		key = array[i + 1];
		for (int j = 0; j < i + 1; j++)
		{
			if (array[i - j] > array[i - j + 1])
			{
				array[i - j + 1] = array[i - j];
				array[i - j] = key;
			}
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	for (const int& element : array)
	{
		cout << element << " ";
	}

#pragma endregion

}
