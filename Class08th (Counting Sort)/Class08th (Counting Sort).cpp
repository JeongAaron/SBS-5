#include <iostream>

using namespace std;

int main()
{
#pragma region 계수 정렬

	//	데이터의 값을 비교하지 않고 각 원소에 데이터가 몇 개 있는 지
	//	개수를 세어 저장한 다음 정렬하는 알고리즘

	int array[] = { 1, 1, 3, 1, 2, 3, 4, 4, 2, 5 };
	int list[5] = { 0, };
	for (int i = 0; i < 10; i++)
	{
		list[array[i] - 1]++;
	}
	for (int i = 0; i < 5; i++)
	{
		if (array[i] != 0)
		{
			for (int j = 0; j < list[i]; j++)
			{
				cout << i + 1 << " ";
			}
			cout << endl;
		}
	}

#pragma endregion

}
