#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int c2(int a)
{
	return a * (a + 1) / 2 % mode;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + i * c2(n / i)) % mode;
	cout << ans;
}