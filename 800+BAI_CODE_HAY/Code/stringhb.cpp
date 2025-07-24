#include <bits/stdc++.h>
using namespace std;
#define int long long 

string s;
int f[111];
void solve()
{
	memset(f,0,sizeof(f));
	int n; cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> s;
		for (char c : s) f[c-'a']++;
	}
	for (char c='a';c<='z';c++) 
	if (f[c-'a']%n!=0) return cout << "NO" << '\n',void();
	cout << "YES" << '\n';

}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("TASK.INP","r",stdin);
	//freopen("TASK.OUT","w",stdout);
	int q; cin >> q;
	while (q--) solve();
}