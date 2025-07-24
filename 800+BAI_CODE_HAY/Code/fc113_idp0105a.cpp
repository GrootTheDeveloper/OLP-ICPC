#include <bits/stdc++.h>
using namespace std;
#define int long long 


int pre[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		pre[i] = pre[i - 1] + (ai > 0) * ai;
	}

	while (q--)
	{
		int l, r; cin >> l >> r;
		cout << pre[r] - pre[l - 1] << '\n';
	}


}