#include <bits/stdc++.h>
using namespace std;

vector<int> g[300000];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n,m; cin >> n >> m;
	for (int i=1;i<=m;i++)
	{
		int u,v; cin >> u >> v;
		g[u].push_back(v);
	}
	int res=0;
	for (int i=1;i<=n;i++) res+=((int)g[i].size()!=0);
	cout << res;
}