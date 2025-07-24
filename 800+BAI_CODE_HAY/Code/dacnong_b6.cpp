#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define val first
#define id second

int a[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, x, q; cin >> n >> x >> q;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		a[i] = a[i - 1] + (ai > 0 && ai < x);
	}
	while (q--)
	{
		int l, r; cin >> l >> r;
		cout << a[r] - a[l - 1] << '\n';
	}
}