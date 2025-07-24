#include <bits/stdc++.h>
using namespace std;
#define int long long 

int solve(int a, int b)
{
	unordered_map <int, bool> f;
	while (a!=0)
	{
		f[a]=true;
		if (a&1) a=(a-1)/2;
		else a/=2;
	}
	while (f[b]!=1)
	{
		if (b&1) b=(b-1)/2;
		else b/=2;
	}
	return b;
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int t; cin >> t;
	int a,b;
	while (t--)
	{
		cin >> a >> b;
		cout << solve(a,b) << '\n';
	}
}