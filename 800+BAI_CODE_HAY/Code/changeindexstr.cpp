#include <bits/stdc++.h>
using namespace std;
#define int long long 

int pre[1000005];
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,q; cin >> n >> q;
	string s; cin >> s;
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i-1] + s[i-1] - 'a' + 1;
	for (int l,r; q; q--)
	{
		cin >> l >> r;	
		cout << pre[r] - pre[l - 1] << '\n';
	}
}