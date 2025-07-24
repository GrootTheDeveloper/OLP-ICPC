#include <iostream>
#include <math.h>
using namespace std;
bool nt(int n){
	if (n<2)
	{
		return 0;
	}
	for (int i=2; i<=sqrt(n); i++)
	{
		if (n%i==0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	cout << "nhap n:";
	int n;
	cin >> n;
	if (nt(n))
	{
		cout << n << " La so nt ";
	}
	else 
	{
		cout << n << " Ko la so nt ";
	}
	return 1;
}
