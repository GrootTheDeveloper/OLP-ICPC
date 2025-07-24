#include <bits/stdc++.h>
using namespace std;

struct node
{
	int u, d, c;
}Q[100005];

bool mark[100005][11];
int colr[100005];
vector<int> g[100005];

void fillcol(int u, int d, int c)
{
	if (mark[u][d] || d < 0) return;
	mark[u][d] = true;
	if (colr[u] == 0) colr[u] = c;
	for (int v : g[u])
		fillcol(v, d - 1, c);
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int q; cin >> q;
	for (int i = 1; i <= q; i++)
		cin >> Q[i].u >> Q[i].d >> Q[i].c;
	for (int i = q; i >= 1; i--)
		fillcol(Q[i].u, Q[i].d, Q[i].c);
	for (int i = 1; i <= n; i++) 
		cout << colr[i] << '\n';
}