#include <bits/stdc++.h>
using namespace std;
#define int long long 
int f[256];

void solve()
{
	memset(f,0,sizeof(f));
	string s; cin >> s;
	for (char c : s) f[(int)c]++;
	for (int i=0;i<s.size();i++) 
	if (f[(int)s[i]]==1) return cout << i+1 << '\n',void();
	cout << -1 << '\n';
}



main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("bai4.inp","r",stdin);
	freopen("bai4.out","w",stdout);
	int k; cin >> k;
	while (k--) solve();
}