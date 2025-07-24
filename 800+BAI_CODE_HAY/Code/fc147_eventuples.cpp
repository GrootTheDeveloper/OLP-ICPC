#include <bits/stdc++.h>
using namespace std;
#define int long long 

int comb2(int n)
{
	return n * (n - 1) / 2;
}
int comb3(int n)
{
	return n * (n - 1) * (n - 2) / 6;
}
int od[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	for (int i = 1, ai; i <= n; i++) cin >> ai, od[i] = od[i - 1] + (ai&1);
	while (q--)
	{
		int l, r; cin >> l >> r;
		int odd = od[r] - od[l - 1], ev = (r - l + 1) - odd;
		cout << comb3(ev) + comb2(odd) * ev << '\n';
	}
}