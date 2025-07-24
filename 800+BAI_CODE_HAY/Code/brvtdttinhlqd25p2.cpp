#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 31 + 01 + 2007;

int bit[N], a[N], trace[N];
vector<int> b;
int LIM;

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("CROAD.INP","r",stdin);
	freopen("CROAD.OUT","w",stdout);
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] -= k;
		a[i] += a[i - 1];
		b.push_back(a[i]);
	}

	b.push_back(0);
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());

	memset(trace, -1, sizeof(trace));
	int rot = lower_bound(b.begin(), b.end(), 0) - b.begin() + 1;
	trace[rot] = 0;

	int u = 0, ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
		int tmp = (trace[pos] == -1? 1e9 : trace[pos]);
		if (i - tmp > ans) u = tmp + 1, ans = i - tmp;
		if (trace[pos] == -1) trace[pos] = i;
	}
	if (ans == 0) cout << 0;
	else cout << u << ' ' << ans;
}