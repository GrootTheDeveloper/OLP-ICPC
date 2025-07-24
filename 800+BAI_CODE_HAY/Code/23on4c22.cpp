#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[200005];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
	sort(a + 1, a + n + 1);
	int res = 0;
	for (int i = n; i >= 2; i--)
	{
		sum -= a[i];
		res += a[i] * (i - 1) - sum; 
	}
	cout << res;
}