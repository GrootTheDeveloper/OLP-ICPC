#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector <int> g[100001],rg[100001], v[100001];
bool visited[100001];
stack <int> st;
int cnt = 0;

void DFSTOPO(int u)
{
	visited[u] = true;
	for (int v : g[u])
		if (!visited[v]) 
			DFSTOPO(v);
	st.push(u);
}
void DFS(int u)
{
	visited[u] = true;
	for (int x : rg[u])
		if (!visited[x]) 
			DFS(x);
	v[cnt].push_back(u);
}

void solve()
{
	int n,m; cin >> n >> m;
	memset(visited, false, sizeof(visited));
	for (int u, v, i = 1; i <= m; i++)
	{
		cin >> u >> v;
		g[u].push_back(v);
		rg[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		if (!visited[i]) DFSTOPO(i);

	memset(visited, false, sizeof(visited));
	while (st.size())
	{
		int x = st.top(); st.pop();
		if (!visited[x])
		{
			cnt++;
			DFS(x);
		}
	}
	if (cnt == 1) return cout << "YES",void();
	else cout << "NO\n" << v[2][0] << ' ' << v[1][0];
	
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t = 1;
	while (t--)
		solve();
}