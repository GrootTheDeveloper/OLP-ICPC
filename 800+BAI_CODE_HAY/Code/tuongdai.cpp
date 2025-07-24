#include <bits/stdc++.h>
using namespace std;
#define int long long 
int u,v,ai;
int f[100005];
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,k; cin >> n >> k;
	for (int i=1;i<=n;i++)
	{
		cin >> ai;
		f[i]=f[i-1]+ai;
	}
	while (k--)
	{
		cin >> u >> v;
		cout << f[v]-f[u-1] << ' ';
	}
}