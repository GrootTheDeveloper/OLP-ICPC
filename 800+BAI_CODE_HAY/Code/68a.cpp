#include <bits/stdc++.h>
using namespace std;
#define int long long 
int s,k;
int calc(int n)
{	
	return n*(n-1)/2;
}
void solve()
{
	int res=0;
	for (int i=2;calc(i)*k<=s;i++)
	{
		int m=s-calc(i)*k;
		res+=(m%i==0 && m!=0);
	}
	cout << res << '\n';
}

main()
{
	freopen("bai1.inp","r",stdin);
	freopen("bai1.out","w",stdout);
	int t; cin >> t;
	while (t--)
	{
		cin >> s >> k;
		solve();
	}
}