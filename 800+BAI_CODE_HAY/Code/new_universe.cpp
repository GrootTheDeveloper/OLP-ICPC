#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int, int>
#define fi first
#define se second
int d[100005];
vector <ii> g[100005];
const int inf = 1e9;
int n, m;
int a[100005];
bool mark[100005];
void sub1()
{
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			int gcd = __gcd(a[i], a[j]);
			// if (gcd > 1) 
			// {
				g[i].push_back({j, (a[i] + a[j])/gcd});
				g[j].push_back({i, (a[i] + a[j])/gcd});
			//}
		}
	fill(d + 1, d + n + 1, inf);
	d[1] = 0;
	mark[1] = true;
	queue <int> q;
	q.push(1);
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (auto x : g[u])
		{
			int v = x.fi, w = x.se;
			if (!mark[v])
			{
				d[v] = d[u] + w;
				mark[v] = true;
				q.push(v);
			} else if (d[v] > d[u] + w)
			{
				d[v] = d[u] + w;
				q.push(v);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int gcd = __gcd(a[1], a[i]);
		cout << min(d[i], (a[1] + a[i]) / gcd) << ' ';
	}
}


void sub2()
{
	for (int i = 1; i <= n; i++) cout << (i == 1? 0 : 2) << '\n';

}

vector <int> b[100005];
void sub3()
{

}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("newuniverse.inp","r",stdin);
	//freopen("newuniverse.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	if (n <= 1000) sub1();
	else if (a[1] == a[2] && a[n - 1] == a[n]) sub2();
	//sub1(); 
	//sub2();
	//0 3 7 5 6 4 3 8 6 7
}
