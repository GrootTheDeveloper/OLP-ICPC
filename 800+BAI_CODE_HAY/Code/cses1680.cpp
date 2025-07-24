#include <bits/stdc++.h>
using namespace std;
#define int long long 

int nxt[100005], in[100005], dp[100005];
vector <int> g[100005];
bool vs[100005];
void dfs(int u)
{
	vs[u] = true;
	int ver = 0;
	for (int v : g[u])
	{
		if (!vs[v]) dfs(v);
		if (dp[v])
		{
			if (dp[u] < dp[v] + 1) ver = v;
		}
	}
	if (ver) dp[u] = dp[ver] + 1, nxt[u] = ver; 
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v; cin  >> u >> v;
		g[u].push_back(v);
		in[v]++;
	}
	queue <int> st;
	for (int i = 1; i <= n; i++) 
		if (!in[i]) st.push(i);
	vector <int> vec;
	while (st.size())
	{
		int u = st.front(); st.pop();
		vec.push_back(u);
		for (int v : g[u])
			if (--in[v] == 0) st.push(v);
	}
	reverse(begin(vec), end(vec));
	dp[n] = 1;
	for (int x : vec)
		if (!vs[x]) dfs(x);
	if (dp[1] == 0) return cout << "IMPOSSIBLE", 0;
	vector <int> path;
	for (int u = 1; u != 0; u = nxt[u]) path.push_back(u);
	cout << path.size() << '\n';
	for (int x : path) cout << x << ' ';

}