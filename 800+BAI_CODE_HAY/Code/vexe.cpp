#include <bits/stdc++.h>
using namespace std;
#define int long long 
int dp[5555],t[5001][5001];
bool vis[5555];
int n,m;
vector <int> d[5555];
void dfs(int u)
{
	vis[u]=true;
	if (u!=n)
	{
		for (int v : d[u])
			if (vis[v]==false && dp[v]>dp[u]+t[u][v]) dp[v]=dp[u]+t[u][v],dfs(v);
	}
	vis[u]=false;
	
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i=1;i<=m;i++)
	{
		int u,v,k;
		cin >> u >> v >> k;
		d[u].push_back(v);
		d[v].push_back(u);
		t[u][v]=t[v][u]=k;
	}
	for (int i=1;i<=n;i++) dp[i]=INT_MAX;
	dp[1]=0;
	dfs(1);
	cout << dp[n];
}