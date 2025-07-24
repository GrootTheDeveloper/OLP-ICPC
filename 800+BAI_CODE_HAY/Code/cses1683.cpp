#include <bits/stdc++.h>
using namespace std;
#define int long long 

int cnt,n,m,pos[200005];

vector <int> g[200005],rg[200005], vi[200005];

bool visited[200005];

stack <int> st;

void topo(int u)
{
	visited[u] = true;
	for (int v : g[u])
		if (!visited[v])
			topo(v);
	st.push(u);
}
void DFS(int u)
{
	visited[u] = true;
	for (int v : rg[u])
		if (!visited[v]) DFS(v);
	pos[u] = cnt;
}

void solve()
{
	for (int i = 1; i <= n; i++)
		if (!visited[i]) topo(i);
	
	memset(visited,false,sizeof(visited));
	while (st.size())
	{
		int x = st.top(); st.pop();
		if (!visited[x])
		{
			cnt++;
			DFS(x);
		}
	}
	
	cout << cnt << '\n';
	for (int i = 1; i <= n; i++) cout << pos[i] << ' ';
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int u,v, i = 1; i <= m; i++)
	{
		cin >> u >> v;
		g[u].push_back(v);
		rg[v].push_back(u);
	}
	solve();
}