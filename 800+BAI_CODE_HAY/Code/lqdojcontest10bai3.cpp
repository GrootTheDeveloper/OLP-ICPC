#include <bits/stdc++.h>
using namespace std;
#define int long long


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	int mx=0,res=0,ai;
	for (int i=1;i<=n;i++)
	{
		cin >> ai;
		if (ai < mx) res+=mx-ai;
		else mx=ai;
	}
	cout << res;
}