#include <bits/stdc++.h>
using namespace std;
#define int long long
long double n;
int calc(int n)
{
	return n*(n+1)/2;
}
long double f[1000006];
void o_o()
{
	long double sum=0;
	for (int i=1;i<=1e6;i++)
	{
		sum+=(long double)1/calc(i);
		f[i]=sum;
	}
}
main()
{
	int t; cin >> t;
	//o_o();
	cout << setprecision(8) << fixed;
	while (t--)
	{
		cin >> n; 
		cout << 2 - (long double)2/(n+1)<< '\n';
	}
		
}