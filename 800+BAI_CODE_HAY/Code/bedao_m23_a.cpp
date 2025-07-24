#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
	string s;
	cin >> s;
	if (s.size()==1) return cout << -1 << '\n',void();
	if (s.size()==2)
	{
		if (s[0]!=s[1]) return cout << 1 << '\n',void();
		else return cout << 0 << '\n',void();
	}
	int res=1;
	for (int i=1;i<s.size()-1;i++)
	{
		if (s[i]==s[i-1] || s[i]==s[i+1] || s[i-1]==s[i+1]) res=0;
	}
	cout << res << '\n';
}


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
}