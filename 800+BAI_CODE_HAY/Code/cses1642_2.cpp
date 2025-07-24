#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int>
#define fi first 
#define se second
int a[1111];
unordered_map <int,vector<ii>> f;


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,x; cin >> n >> x;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<n;i++)
		for (int j=i+1;j<=n;j++)
		{
			if (f.find(x-a[i]-a[j])!=f.end())
			{
				for (ii c : f[x-a[i]-a[j]])
					if (c.fi!=i && c.fi!=j && c.se!=i && c.se!=j)
				return cout << i << ' ' << j << ' ' << c.fi << ' ' << c.se,0; 
			}
			f[a[i]+a[j]].push_back({i,j});
		}
	cout << "IMPOSSIBLE";

}