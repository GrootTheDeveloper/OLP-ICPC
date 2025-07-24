#include <bits/stdc++.h>
using namespace std;

int a[100005];
vector<int> b;
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], b.push_back(a[i]);
	sort(b.begin(), end(b));
	b.erase(unique(b.begin(), end(b)), end(b));
	int lim = 0;
	for (int c : b)
		a[++lim] = c;
	int ans = n;
	for (int i = 1; i <= n; i++)
	{
		int nex = a[i] + n - 1;
		int pos = upper_bound(a + 1, a + lim + 1, nex) - a - 1;
		ans = min(ans, n - (pos - i + 1));
	}
	cout << ans;
}