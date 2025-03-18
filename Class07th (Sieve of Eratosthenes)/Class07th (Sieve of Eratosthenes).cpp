#include <iostream>

using namespace std;

bool isPrime(int n)
{
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			count++;
		}
	}
	if (count == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isPrime1(int n)
{
	if (n <= 1)
	{
		return false;
	}
	for (int i = 2; i < n; i++)
	{
		if (n % 2 == 0)
		{
			return false;
		}
	}
	return true;
}

void sieve(int n)
{
	int* array = new int[n + 1];

	for (int i = 0; i <= n; i++)
	{
		array[i] = i;
	}
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (array[i] == 0)
		{
			continue;
		}
		for (int j = i * 2; j <= n; j += i)
		{
			array[j] = 0;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (array[i] != 0)
		{
			cout << array[i] << " ";
		}
	}
	delete[] array;
}
int main()
{
	for (int i = 0; i < 30; i++)
	{
		cout << boolalpha << i << " is Prime Number " << isPrime(i) << endl;
	}
	sieve(16);
}
