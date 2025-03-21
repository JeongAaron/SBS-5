#include <iostream>

#define SIZE 6

using namespace std;

void quick_sort(int list[], int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int pivot = start;
	int left = start + 1;
	int right = end;
	while (left <= right)
	{
		while (left <= end && list[left] <= list[pivot])
		{
			left++;
		}
		while (right > start && list[right] >= list[pivot])
		{
			right--;
		}
		if (left > right)
		{
			std::swap(list[pivot], list[right]);
		}
		else
		{
			std::swap(list[left], list[right]);
		}
	}
	quick_sort(list, start, right - 1);
	quick_sort(list, right + 1, end);
}
int main()
{
#pragma region 퀵 정렬

	//	기준점을 획득한 다음 기준점을 기준으로 배열을 나누고 
	//	한 쪽에는	기준점보다 작은 값들이 위치 하게 하고	
	//	다른 한 쪽에는 기준점 보다 큰 값들이 위치하도록 정렬

	//	나누어진 하위 배열에 대해 재귀적으로 퀵 정렬을 호출하여 
	//	모든 배열이 기본 배열이 될 때 까지 반복 하면서 정렬하는 알고리즘

	int list[SIZE] = { 5,4,6,2,1,3 };
	quick_sort(list, 0, 5);
	for (int i = 0; i < SIZE; i++)
	{
		cout << list[i] << " ";
	}
#pragma endregion

}
