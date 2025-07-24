#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ii pair<int,int> 
int a[200005];
void solve()
{
	int n,k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int res = (a[n] + a[n - k]) - (a[1] + a[1 + k]);
	cout << res << '\n';
	vector <bool> f(n+1,false);
	f[1] = f[1 + k] = f[n - k] = f[n] = true;
	int mx = a[n-k] + a[n], mi = a[1] + a[1 + k];
	
	vector <ii> v;
	v.push_back({1,1+k});
	v.push_back({n-k,n});
	
	for (int i = n - 1; i > 1; i--)
	if (!f[i])
	{
		f[i] = true;
		int idx = i - 1;
		while (true)
		{
			if (f[idx] == false && i-idx <= k && a[i]+a[idx] <= mx && a[i] + a[idx] >= mi) break;
			else idx-- ;
		}
		f[idx] = true;
		v.push_back({idx, i});
	}
	
	sort(v.begin(),v.end(),less<ii>());
	for (ii c : v) cout << c.first << ' ' << c.second << '\n';

}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
}