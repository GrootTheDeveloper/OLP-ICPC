#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int MAX=1e9;
int n,m,s;
struct ii{
	int node,s;
}ans[100005];
bool cmp(ii a, ii b)
{
	if (a.s==b.s) return a.node<b.node;
	return a.s<b.s;
}
vector <int> d[100005];
int dp[100005];
bool us[100005];

void DFS(int u)
{
	us[u]=true;
	for (int v : d[u])
	{
		if (!us[v] && dp[v]>dp[u]+1)
		{
			dp[v]=dp[u]+1;
			DFS(v);
		}
	}
	us[u]=false;
	return;
}
void solve()
{
	DFS(s);
}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("t.inp","r",stdin);
	freopen("t.out","w",stdout);
	cin >> n >> m >> s;
	for (int i=1;i<=m;i++)
	{
		int u,v; cin >> u >> v;
		d[u].push_back(v);
		d[v].push_back(u);
	}
	for (int i=1;i<=n;i++) dp[i]=MAX,us[i]=false;
	dp[s]=0;
	solve();
	int k=0;
	for (int i=1;i<=n;i++)
	if (dp[i]!=MAX)
	{
		k++;
		ans[k].node=i;
		ans[k].s=dp[i];
	}
	sort(ans+1,ans+k+1,cmp);
	for (int i=1;i<=k;i++) cout << ans[i].node << ' ' << ans[i].s << '\n';
	cout << clock()/(double)1000 << "s";

}