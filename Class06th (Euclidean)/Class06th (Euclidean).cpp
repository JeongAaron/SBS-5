#include <iostream>

using namespace std;

int euclid(int x, int y)
{
	while (y != 0)
	{
		int R = x % y;
		if (R == 0)
		{
			return y;
		}
		else
		{
			x = y;
			y = R;
		}
	}
}

int main()
{
#pragma region 유클리드 호제법

	//	2개의 자연수 또는 정식의 최대 공약수를 구하는 방식으로 두 수가
	//	서로 상대방 수를 나누어서 원하는 수를 얻어내는 알고리즘

	int a = 155;
	int b = 65;
	int result = 0;
	for (int i = 1; i <= a && i <= b; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			result = i;
		}
	}

	cout << "최대 공약수 : " << result << " ";
	cout << endl;
	cout << "최대 공약수 : " << euclid(a, b) << " ";

#pragma endregion

}
