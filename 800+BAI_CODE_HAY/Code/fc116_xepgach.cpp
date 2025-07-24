#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define fi first
#define se second

bool cmp1(ii a, ii b)
{
	return a.fi - a.se > b.fi - b.se;
}

bool cmp2(ii a, ii b)
{
	return (a.se - a.fi < b.se - b.fi);
}
vector<ii> g1, g2, g3;
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x, y; cin >> x >> y;
		if (x > y) g1.emplace_back(x, y);
		if (y > x) g3.emplace_back(x, y);
		if (x == y) g2.emplace_back(x, y);
	}

	sort(g1.begin(), g1.end(), cmp1);
	sort(g3.begin(), g3.end(), cmp2);
	int ans = 0;
	int lim = 0;
	for (ii x : g1)
	{
		++lim;
		ans += x.fi * (lim - 1) + x.se * (n - lim);
	}
	for (ii x : g2)
	{
		++lim;
		ans += x.fi * (lim - 1) + x.se * (n - lim);		
	}
	for (ii x : g3)
	{
		++lim;
		ans += x.fi * (lim - 1) + x.se * (n - lim);
	}

	cout << ans;
}