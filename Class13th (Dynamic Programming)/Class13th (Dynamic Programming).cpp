#include <iostream>

#define SIZE 1000

using namespace std;

long long Fibonacci(long long list[], int n)
{
	if (n <= 0)
	{
		return 0;
	}
	if (n <= 2)
	{
		return 1;
	}
	if (list[n] != 0)
	{
		return list[n];
	}
	return list[n] = Fibonacci(list, n - 1) + Fibonacci(list, n - 2);

}
int main()
{
#pragma region 동적 계획법

	//	특정 범위까지의 값을 구하기 위해 그것과 다른 범위까지의 값을 이용해서
	//	효율적으로 값을 구하는 알고리즘

	//	(Overlapping Subproblems)겹치는 부분 문제
	//	동일한 작은 문제들이 반복하여 나타나는 경우를 의미

	//	(Optimal Substructure)최적 부분 구조
	//	부분 문제의 최적 결과 값을 사용하여 전체 문제의 최적 결과를 낼 수 있는 경우를 의미

	//	메모이제이션(Memoiztion)
	//	프로그램이 동일한 계산을 반복해야 할 때, 이전에 계산한 값을 메모리에 저장함으로써
	//	동일한 계산을 반복 수행하는 작업을 제거하여 프로그램의 실행 속도를 향상시키는 방법

	long long list[SIZE] = { 0, };
	cout << Fibonacci(list, 100) << endl;

#pragma endregion
}
