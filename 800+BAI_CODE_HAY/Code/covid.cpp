#include <bits/stdc++.h>
using namespace std;
#define int long long 
vector <int> g[111];
int n,m;


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
	}
	
}