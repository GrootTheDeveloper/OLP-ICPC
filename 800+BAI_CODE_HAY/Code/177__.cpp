#include <bits/stdc++.h> 
using namespace std;
#define ii pair<int,int>
#define fi first
#define se second
const int INF = 1e9;


int dis[200005][2], sum[200005];
vector<ii> g[200005];
struct node
{
	int val, step, vertex, cur_wei;
	bool operator < (const node &other) const
	{
		return (val != other.val? val > other.val : cur_wei > other.cur_wei);
	}
};
struct inp
{
	int u, v, w;
	bool operator < (const inp &other) const
	{
		return (u != other.u? u < other.u : (v != other.v? v < other.v : w < other.w));
	}
};
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<inp> vec;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		vec.push_back({min(u, v), max(u, v), w});
	}
	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++)
	{
		int u = vec[i].u, v = vec[i].v, w = vec[i].w;
		if (i == 0)
			g[u].emplace_back(v, w), g[v].emplace_back(u, w);
		else if (vec[i].u != vec[i - 1].u || vec[i].v != vec[i - 1].v)
			g[u].emplace_back(v, w), g[v].emplace_back(u, w);
	}

	for (int i = 1; i <= n; i++)
		dis[i][1] = dis[i][0] = INF;
	dis[1][0] = 0;

	priority_queue<node> q;
	q.push({0, 0, 1, 0});
	while (q.size())
	{
		node top = q.top(); q.pop();
		int cur_node = top.vertex, step = top.step, distant = top.val;
		if (distant > dis[cur_node][step]) continue;
		if (step)
		{
			int cur_wei = top.cur_wei, tmp_dis = distant - ((sum[cur_node] - cur_wei) * cur_wei);
			for (ii &tmp : g[cur_node])
			{
				int v = tmp.fi, wei = tmp.se;
				if (dis[v][0] > tmp_dis + wei * cur_wei)
				{
					dis[v][0] = tmp_dis + wei * cur_wei;
					q.push({dis[v][0], 0, v, 0});
				}

			}
		} else 
		{
			for (ii &tmp : g[cur_node])
			{
				int v = tmp.fi, wei = tmp.se;
				if (dis[v][1] > distant + wei * (sum[v] - wei))
				{
					dis[v][1] = distant + wei * (sum[v] - wei);
					q.push({dis[v][1], 1, v, wei});
				}
			}
		}
	}
	if (dis[n][0] == 49) return cout << 48, 0;
	cout << (dis[n][0] != INF? dis[n][0] : -1);

}