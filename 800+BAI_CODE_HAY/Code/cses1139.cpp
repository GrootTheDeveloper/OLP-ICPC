#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define val second 


int h[200005],par[200005],n; 
bool visited[200005];
set <int> node[200005]; 
vector <int> d[200005];
priority_queue <ii> q;
int ans[200005];

void down(int u)
{
	visited[u]=true;
	for (int v : d[u])
	{
		if (!visited[v])
		{
			par[v]=u;
			h[v]=h[u]+1;
			q.push({h[v],v});
			visited[v]=true;
			down(v);
		}
	}
}

void solve()
{
	while (q.size())
    {
        ii x=q.top();
        int parr=par[x.val];
        if ((int)node[x.val].size()>(int)node[parr].size()) swap(node[x.val],node[parr]);
        for (auto c : node[x.val]) node[parr].insert(c);
        ans[parr]=node[parr].size();
        q.pop();
    }
	for (int i=1;i<=n;i++) cout << ans[i] << ' ';
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i=1,ai;i<=n;i++)
	{
		cin >> ai;
		node[i].insert(ai);
		ans[i]=1;
	}
	for (int i=1,u,v;i<n;i++)
	{
		cin >> u >> v;
		d[u].push_back(v);
		d[v].push_back(u);
	}
	down(1);
	solve();
}