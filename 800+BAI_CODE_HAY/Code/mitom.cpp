#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i < n; ++i) cin >> a[i];
	int res = 0;
	for (int i = n; i > 0; i--)
		res += max(a[i], a[i-1]);
	cout << res;
}