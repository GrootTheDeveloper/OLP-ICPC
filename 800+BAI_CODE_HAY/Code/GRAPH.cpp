#include <bits/stdc++.h>
using namespace std;
#define int long long

int cnt[100005],n,m,k;
vector <int>  d[100005];
void dfs(int u)
{
	cnt[u]++;
	for (int v : d[u]) if (cnt[v]<k) dfs(v);
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> n >> m;
	int u,v;
	for (int i=1;i<=m;i++)
	{
		cin >> u >> v;
		d[u].push_back(v);
		d[v].push_back(u);
	}
	for (k=1;k<=n;k++)
	{
		cnt[k]++;
		int res=0;
		for (int i=1;i<=n;i++)
		if (cnt[i]<k) res++,dfs(i);
		cout << res << '\n';
	}
}
