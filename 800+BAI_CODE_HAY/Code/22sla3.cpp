#include <bits/stdc++.h>
using namespace std;
#define int long long 

int calc(int a, int b)
{
	return b*(b+1)/2-(a-1)*a/2;
}
main()
{
	int n,m; cin >> n >> m;
	cout << calc(1,m/2+(m&1))+calc(n-m/2+1,n);
}