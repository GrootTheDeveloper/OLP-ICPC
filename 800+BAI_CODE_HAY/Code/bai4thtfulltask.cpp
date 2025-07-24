#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,s;
bool visited[100005];
vector <int> g[100005];
int dp[100005];

struct dta{
	int node,smin;
}ans[100005];
bool cmp(dta a, dta b)
{
	return ((a.smin==b.smin)? a.node<b.node:a.smin<b.smin);
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("t.inp","r",stdin);
	freopen("t.out","w",stdout);
	cin >> n >> m >> s;
	for (int i=1,x,y;i<=m;i++)
	{
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	queue <int> q;
	q.push(s);
	visited[s]=true;
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		for (int v : g[u])
			if (!visited[v])
			{
				q.push(v);
				dp[v]=dp[u]+1;
				visited[v]=true;
			}
	}
	int k=0;
	for (int i=1;i<=n;i++)
	{
		if (visited[i]) 
		{
			k++;
			ans[k].node=i;
			ans[k].smin=dp[i];
		}
	}
	sort(ans+1,ans+k+1,cmp);
	for (int i=1;i<=k;i++) cout << ans[i].node << ' ' << ans[i].smin << '\n';
	cout << clock()/(double)1000 << "s";

}