#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector <int> idx[100005];

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		idx[ai].push_back(i);
	}
	while (q--)
	{
		int l,r,x; cin >> l >> r >> x;
		cout << upper_bound(idx[x].begin(), idx[x].end(), r) - lower_bound(idx[x].begin(), idx[x].end(), l) << '\n';
	}
}