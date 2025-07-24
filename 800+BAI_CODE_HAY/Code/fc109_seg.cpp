#include <bits/stdc++.h>
using namespace std;

int a[500005];
vector<int> g[500005];
bool mark[500005];
void dfs(int u)
{
	for (int v : g[u])
	if (a[v] <= a[u])
	{
		a[v] = a[u] + 1;
		dfs(v);
	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int n = s.size();
	s = " " + s;
	for (int i = 1; i <= n; i++)
	{
		if (s[i] == '<')
		{
			g[i].push_back(i + 1);
			mark[i + 1] = true;
		} else
		{
			g[i + 1].push_back(i);
			mark[i] = true;
		}
	}
	memset(a, - 1, sizeof(a));
	for (int i = 1; i <= n + 1; i++)
	if (!mark[i]) dfs(i);
	long long ans = 0;
	for (int i = 1; i <= n + 1; i++)
		ans += a[i];
	cout << ans;
}