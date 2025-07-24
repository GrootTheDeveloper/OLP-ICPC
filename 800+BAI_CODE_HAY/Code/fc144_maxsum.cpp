#include <bits/stdc++.h>
using namespace std;
#define int long long 

int a[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i < n; i++) cin >> a[i];
	int ans = a[1] + a[n - 1];
	for (int i = 2; i < n; i++) ans += min(a[i], a[i - 1]);
	cout << ans;
}