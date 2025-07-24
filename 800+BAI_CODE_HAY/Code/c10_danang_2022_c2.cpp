#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	vector<int> b;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		b.push_back(ai);
	}
	sort(b.begin(), b.end(), greater<int>());
	b.erase(unique(b.begin(), b.end()), b.end());
	int ans = 0;
	for (int i = 0; i < min(k, (int)b.size()); i++)
		ans += b[i];
	cout << ans << '\n';
	for (int c : b) cout << c << ' ';
}