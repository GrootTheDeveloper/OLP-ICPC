#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n/2;i++)
	for (int j=1;j<=n/3;j++)
	if (i*2+j*3==n) return cout << i << ' ' << j,0;
	cout << -1;
}