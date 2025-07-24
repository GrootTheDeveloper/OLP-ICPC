#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector <pair<int,int>> v;
vector <int> d[100005];
bool uses[100005];

void DFS(int u)
{
	uses[u]=true;
	for (int v : d[u])
		if (!uses[v]) DFS(v);
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m; cin >> n >> m;
	int x,y;
	for (int i=1;i<=m;i++)
	{
		cin >> x >> y;
		d[x].push_back(y);
		d[y].push_back(x);
	}
	DFS(1);
	int c=1;
	for (int i=2;i<=n;i++)
	{
		if (!uses[i])
		{
			v.push_back(make_pair(c,i));
			c=i;
			DFS(i);
		}
	}
	cout << v.size() << '\n';
	for (pair<int,int> i : v)
		cout << i.first << ' ' << i.second << '\n';
}