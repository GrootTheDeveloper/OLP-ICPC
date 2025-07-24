#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int inf = 1e15;
struct node
{
	int u, v, w;
}eg[100005];
int d[3][100005], n, m, p;
vector <int> g[100005];
void dijkstra(int s)
{
	vector <bool> mark(n + 5, false);
	fill(d[s] + 1, d[s] + n + 1, inf);
	mark[s] = 1;
	d[s][s] = 0;
	queue <int> q;
	q.push(s);
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (int id : g[u])
		{
			int v = eg[id].u + eg[id].v - u, w = eg[id].w;
			if (!mark[v])
			{
				d[s][v] = d[s][u] + w;
				q.push(v);
				mark[v] = true;
			} else
			{
				if (d[s][v] > d[s][u] + w)
				{
					d[s][v] = d[s][u] + w;
					q.push(v);
				}
			}
		}
	}
}
void sub1()
{
	while (p--)
	{
		int T, W; cin >> T >> W;
		int temp = eg[T].w, u = eg[T].u, v = eg[T].v;
		eg[T].w = W;
		dijkstra(1);
		dijkstra(2);
		int ans1 = 0, ans2 = 0;
		for (int i = 1; i <= n; i++)
		{
			if (d[1][i] <= d[1][u] && d[2][i] <= d[2][u]) ans1++;
			if (d[1][i] <= d[1][v] && d[2][i] <= d[2][v]) ans2++;
		}
		cout << ans1 << ' ' << ans2 << '\n';
		eg[T].w = temp;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("IMPEVAL.INP","r",stdin);
	freopen("IMPEVAL.OUT","w",stdout);
	cin >> n >> m >> p;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		eg[i] = {u, v, w};
		g[u].push_back(i);
		g[v].push_back(i);
	}
	if (m <= 1000 && p <= 1000) sub1();
}