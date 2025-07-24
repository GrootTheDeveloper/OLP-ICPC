#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define init memset(vs, false, sizeof(vs))

const int maxn = 5e4 + 5;

vector <int> g[maxn], rg[maxn];
int n, m, q, cnt, pos[maxn];
bitset <maxn> d[maxn];
stack <int> st;
bool vs[maxn];
void topo(int u)
{
	if (vs[u]) return;
	vs[u] = true;
	for (int v : g[u]) topo(v);
	st.push(u);
}

void vr(int u)
{
	if (vs[u]) return;
	vs[u] = true;
	for (int v : rg[u]) vr(v);
	d[cnt].set(u);
	pos[u] = cnt;
}

void setup(int u)
{
	if (vs[u]) return;
	vs[u] = true;
	for (int v : g[u]) setup(v), d[pos[u]] |= d[pos[v]];
}

void solve()
{
	for (int i = 1; i <= n; i++) topo(i);
	init;
	
	while (st.size())
	{
		int x = st.top(); st.pop();
		if (!vs[x]) cnt++, vr(x);
	}

	init;
	for (int i = 1; i <= n; i++) setup(i);
	while (q--)
	{
		int a,b; cin >> a >> b;
		cout << ((d[pos[a]][b] == 1) ? "YES\n" : "NO\n");
	}

}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1, u,v; i <= m; i++)
	{
		cin >> u >> v;
		g[u].push_back(v);
		rg[v].push_back(u);
	}
	solve();
}