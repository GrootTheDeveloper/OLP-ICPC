#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define iii pair<ii,int>
#define se second
#define fi first
#define id second
bool cmp(iii a, iii b)
{
	return a.fi.se < b.fi.se;
}
iii a[1001];
int dp[1001], par[1001];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("PHONGHOP.INP","r",stdin);
	freopen("PHONGHOP.OUT","w",stdout);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].fi.fi >> a[i].fi.se;
		a[i].id = i;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = i - 1; j >= 1; j--)
			if (a[j].fi.se <= a[i].fi.fi && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
				par[i] = j;
			}
	}
	int pos = 0;
	for (int i = 1; i <= n; i++) if (dp[i] > dp[pos]) pos = i;
	vector <int> vec;
	for (int i = pos; i != 0; i = par[i]) vec.push_back(a[i].id);
	reverse(vec.begin(), vec.end());
	cout << dp[pos] << '\n';
	for (int x : vec) cout << x << ' ';
}