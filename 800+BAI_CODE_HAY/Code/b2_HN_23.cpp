#include <bits/stdc++.h>
using namespace std;
#define int long long


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,x; cin >> n >> x;
	int res=0;
	for (int i=1;i<=n;i++)
	if (x%i==0) res+=(x/i<=n);
	cout << res;
}