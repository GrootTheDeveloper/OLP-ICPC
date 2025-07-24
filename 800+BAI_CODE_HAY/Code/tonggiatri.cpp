#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;
int a[1000006], pre[1000006];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], pre[i] = pre[i - 1] + a[i];
	int res = 0;
	for (int i = 2; i < n; i++)
		res = (res + (a[i] * pre[i - 1] % mode) * ((pre[n] - pre[i]) % mode)) % mode;
	cout << res;
}