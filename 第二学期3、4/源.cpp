#include<iostream>
#include<cmath>
using namespace std;

int * f(int a[], int n)
{
	if (n == 1)
	{
		cin >> a[0];
		return &a[0];
	}

	else
	{
		int * p = f(a, n - 1);
		p++;
		cin >> *p;
		int New = *p;
		int i = 0;
		for (; i<int(pow(2, n - 1)) - 1; i++)
		{
			p++;
			*p = a[i];
			a[i] += New;
		}
		return p;
	}
}

int main()
{
	int N = 0, count = 0, S = 0;
	cin >> S;
	cin >> N;
	int sum[1000] = { 0 };
	int *P = f(sum, N);
	for (int i = 0; i<int(pow(2, N)) - 1; i++)
	{
		if (sum[i] == S)
			count++;

	}
	P = NULL;
	cout << count;
	//system("pause");
	return 0;
}