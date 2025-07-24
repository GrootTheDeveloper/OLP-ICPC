#include <bits/stdc++.h>
using namespace std;
#define int long long 

int cnt;
int pos[100005];
vector <int> d[100005];
bool used[100005];

void DFS(int u)
{
	pos[u]=cnt;
	used[u]=true;
	for (int v : d[u])
		if (!used[v]) DFS(v);
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int n,m; cin >> n >> m;
	for (int i=1;i<=m;i++)
	{
		int x,y; cin >> x >> y;
		d[x].push_back(y);
		d[y].push_back(x);
	}
	for (int i=1;i<=n;i++)
		if (!used[i])
		{
			cnt++;
			DFS(i);
		}
	if (cnt==1) return cout << "IMPOSSIBLE",0;
	for (int i=1;i<=n;i++)
		if (pos[i]==1) 
			cout << 1 << ' ';
		else
			cout << 2 << ' ';
}