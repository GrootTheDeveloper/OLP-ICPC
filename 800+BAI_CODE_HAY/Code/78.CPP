//https://marisaoj.com/problem/78
#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100005];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k; cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i]; a[i] += a[i-1];
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		int pos = upper_bound(a , a + i + 1, a[i] - k) - a;
		res += pos;
	}
	cout << res;
}