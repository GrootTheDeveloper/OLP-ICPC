#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

struct node{
    int x,y,w;
    bool operator<(const node &other) const{
        return w > other.w;
    }
}option[10005];

vector <ii> g[2002];

int d[2002][2002], n, m, q;
const int inf = 1e9;

void dijkstra(int s)
{
	priority_queue <ii, vector<ii>, greater<ii>> q;
	d[s][s] = 0;
	q.push({d[s][s], s});
	while (q.size())
	{
		ii top = q.top(); q.pop();
		int kc = top.fi, u = top.se;
		if (kc > d[s][u]) continue;
		for (auto x : g[u])
		{
			int v = x.fi, w = x.se;
			if (d[s][v] > d[s][u] + w)
			{
				d[s][v] = d[s][u] + w;
				q.push({d[s][v],v});
			}
		}
	}

}

void inp()
{
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++)
	{
		int x,y,w; cin >> x >> y >> w;
		option[i] = {x,y,w};
		g[x].push_back({y,w});
	}
	sort(option + 1, option + m + 1);
}

void solve()
{
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) d[i][j] = inf;
	for (int i = 1; i <= n; i++)
		dijkstra(i);
	while (q--)
	{
		int s,t; cin >> s >> t;
		int res = d[1][s];
		for (int i = 1; i <= m; i++)
		{
			int x = option[i].x, y = option[i].y, w = option[i].w;
			res = min(res, d[1][x] + d[y][s] + t);
			if (option[i].w < t) break;
		}
		cout << res << '\n';

	}
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
 	inp();
 	solve();
}
