#include <bits/stdc++.h>
using namespace std;
#define int long long


int power(int a, int b, int mode)
{
	int res=1;
	while(b)
	{
		if (b&1)
			res=(res*a)%mode;
		a=(a*a)%mode;
		b/=2;
	}
	return res;
}

bool test(int a, int n, int k, int m)
{
	int mode=power(a,m,n);
	if (mode==1 || mode==n-1) return true;
	for (int i=1;i<=k;i++)
	{
		mode=(mode*mode)%n;
		if (mode==n-1) return true;
	}
	return false;
}

bool nto(int n)
{
	if (n==2 || n==3 || n==5 || n==7) return true;
	if (n<11) return false;
	int k=0,m=n-1;
	while (m%2==0) k++,m/=2;
	vector <int> settest={2,3,5,7,11,13,17,19,23,29,31,37};
	for (int a : settest)
		if (!test(a,n,k,m)) return false;
	return true;
}


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	vector <int> v;
	v.push_back(1);v.push_back(2);
	while (v.back()+v[v.size()-2]<=1e16) v.push_back(v.back()+v[v.size()-2]);
	for (int c : v)
	{
		cout << c << ' ';
		if (nto(c)) cout << "YES";
		else cout << "NO";
		cout << '\n';
	}
}