#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
const int inf = 1e12;
struct dta
{
	int cost, u, type, money;
	dta (int _a, int _b, int _c, int _d) 
	{
		cost = _a;
		u    = _b;
		type = _c;
		money= _d;
	}
	bool operator<(const dta &other) const
	{
		return cost > other.cost;
	}
};

int d[3][10005];
vector <iii> g[10004];
int change(int k, int money)
{
	return (k - money)/ 100 + ((k - money) % 100 != 0);
}
bool f[10004];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m; cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x,y,c,d; cin >> x >> y >> c >> d;
		g[x].push_back({y,{d,c}});
		g[y].push_back({x,{d,c}});
	}
	int k ; cin >> k;
	for (int i = 1; i <= n; i++) d[1][i] = d[2][i] = inf;
	d[1][1] = 0;
	priority_queue <dta> q;
	q.push(dta(0,1,1,k));
	int res = inf;
	while (q.size())
	{
		dta top = q.top(); q.pop();
		int cost = top.cost, u = top.u, type = top.type, money = top.money;
		if (cost > d[type][u]) continue;
		if (u == n) 
		{
			int ans = cost;
			if (f[n]) ans -= money/100;
			res = min(res,ans);
			continue;
		}
		for (auto x : g[u])
		{
			int v = x.fi, di = x.se.se, ci = x.se.fi;
			if (type == 1)
			{
				if (ci <= money)
				{
					if (d[type][v] > d[type][u] + ci)
					{
						f[v] = (f[v] || f[u]);
						d[type][v] = d[type][u] + ci;
						q.push(dta(d[type][v], v, 1, money - ci));
					}
				}
				else if (ci > money)
				{
					int l = change(k, money);
					if (d[type][v] > d[type][u] + ci + l)
					{
						f[u] = true;
						d[type][v] = d[type][u] + ci + l;
						q.push(dta(d[type][v], v, 1, k - ci));
					}		
				}
				if (di + 1 <= money)
				{
					if (d[2][v] > d[1][u] + di + 1)
					{
						f[v] = (f[v] || f[u]);
						d[2][v] = d[1][u] + di + 1;
						q.push(dta(d[2][v], v, 2, money - di - 1));
					}
				}
				else if (di + 1 > money)
				{
					int l = change(k, money);
					if (d[2][v] > d[1][u] + di + l + 1)
					{
						f[u] = true;
						d[2][v] = d[1][u] + di + l + 1;
						q.push(dta(d[2][v], v, 2, k - di - 1));
					}		
				}

			}

			if (type == 2)
			{
				if (di <= money)
				{
					if (d[type][v] > d[type][u] + di)
					{
						f[v] = (f[v] || f[u]);
						d[type][v] = d[type][u] + di;
						q.push(dta(d[type][v], v, 2, money - di));
					}
				}
				else if (di > money)
				{
					int l = change(k, money);
					if (d[type][v] > d[type][u] + di + l)
					{
						f[u] = true;
						d[type][v] = d[type][u] + di + l;
						q.push(dta(d[type][v], v, 2, k - di));
					}		
				}
				if (ci + 1 <= money)
				{
					if (d[1][v] > d[2][u] + ci + 1)
					{
						f[v] = (f[v] || f[u]);
						d[1][v] = d[2][u] + ci + 1;
						q.push(dta(d[1][v], v, 1, money - ci - 1));
					}
				}
				else if (ci + 1 > money)
				{
					f[u] = true;
					int l = change(k, money);
					if (d[1][v] > d[2][u] + ci + l + 1)
					{
						d[1][v] = d[2][u] + di + l + 1;
						q.push(dta(d[1][v], v, 1, k - ci - 1));
					}		
				}

			}
		}
	}
	cout << res; 

}