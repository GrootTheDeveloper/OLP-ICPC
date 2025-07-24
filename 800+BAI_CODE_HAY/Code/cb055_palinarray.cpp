#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[100005],n,f[100005];
void solve()
{
	memset(f,0,sizeof(f));
	for (int i=1;i<=n;i++)
	{
		if (f[a[i]]!=0 && f[a[i]]!=i-1) return cout << "YES" << '\n',void();
		if (f[a[i]]==0) f[a[i]]=i;
	}
	cout << "NO" << '\n';	
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i=1;i<=n;i++) cin >> a[i];
		solve();
	}
}