#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e15;
string s, t;
vector <int> d[30];
int dp[30][5005];
void solve()
{
	cin >> s >> t;
	s = " " + s;
	t = " " + t;
	int m = s.size() - 1, n = t.size() - 1;
	for (int i = 1; i <= m; i++) d[s[i] - 'a'].push_back(i);
	for (int i = 0; i <= 25; i++) for (int j = 1; j <= n; j++) dp[i][j] = inf;
	
	for (int l = 1; l <= n; l++)
	{
		int x = t[l] - 'a';
		for (int i = l - 1; i >= 0; i--)
			if (dp[x][i] != inf)
			{
				auto it = upper_bound(d[x].begin(), d[x].end(), dp[x][i]);
				if (it != d[x].end()) {dp[x][i + 1] = min(dp[x][i + 1], *it); break;}
			}
		for (char c = 'a'; c <= 'z'; c++) if (c != t[l])
		{
			int mark = c - 'a';
			for (int i = l - 1; i >= 0; i--)
				if (dp[mark][i] != inf)
				{
					auto it = upper_bound(d[x].begin(), d[x].end(), dp[mark][i]);
					if (it != d[x].end()) {dp[x][i + 1] = min(dp[x][i + 1], *it); break;}
				}

		}
		
	}
	int res = 0;
	for (char c = 'a'; c <= 'z'; c++)
	{
		int x = c - 'a';
		for (int i = res; i <= n; i++) if (dp[x][i] != inf) res = i;
	}
	cout << res;


}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
}