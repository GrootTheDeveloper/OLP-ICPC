#include <bits/stdc++.h>
using namespace std;
#define int long long 

pair <int, int> ans[100005];
int a[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int pos = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] > a[pos]) pos = i;
	}
	vector <int> v;
	for (int i = pos + 1; i <= n; i++) v.push_back(a[i]);
	for (int i = 1; i < pos; i++)
	{
		v.push_back(min(a[i], a[i + 1]));
		ans[i] = {a[i], a[i + 1]};
		a[i + 1] = max(a[i], a[i + 1]);
	}
	int q; cin >> q;
	while (q--)
	{
		int k; cin >> k;
		if (k < pos) cout << ans[k].first << ' ' << ans[k].second << '\n';
		else
		{
			k %= v.size();
			if (k == 0) k = v.size();
			cout << a[pos] << ' ' << v[k - 1] << '\n';
		}
	}
}
