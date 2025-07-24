#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[100005], r[100005], l[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		int pos = i - 1;
		while (a[pos] >= a[i]) pos = l[pos];
		l[i] = pos;	
	}
	for (int i = n; i >= 1; i--)
	{
		int pos = i + 1;
		while (a[pos] >= a[i]) pos = r[pos];
		r[i] = pos;
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		res = max(res, a[i] * (r[i] - l[i] - 1));
	cout << res;
}