#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n,m;
vector <int> g[100005];
int dp[100005],par[100005];
bool visited[100005];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin >> n >> m;
	for (int i=1,x,y;i<=m;i++)
	{
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	queue <int> q;
	q.push(1);
	visited[1]=true;
	dp[1]=1;
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		for (int v : g[u])
		{
			if (!visited[v])
			{
				q.push(v);
				visited[v]=true;
				dp[v]=dp[u]+1;
				par[v]=u;
			}
		}
	}
	if (!visited[n]) return cout << "IMPOSSIBLE",0;
	cout << dp[n] << '\n';
	vector <int> v;
	while (n!=0)
	{
		v.push_back(n);
		n=par[n];
	}
	reverse(v.begin(),v.end());
	for (int c : v) cout << c << ' ';


}