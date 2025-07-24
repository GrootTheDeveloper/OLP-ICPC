#include <bits/stdc++.h>
using namespace std;
#define int long long 


vector <int> v[100005];
int f[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int lim = 0;
	for (int i = 1; i <= n; i++)
	{
		int ai, ci; cin >> ai >> ci;
		v[ci].push_back(ai);
		lim = max(lim, ci);
	}
	for (int i = 1; i <= lim; i++)
	{
		int sum = 0;
		for (int &c : v[i])
		{
			sum += c;
			c = sum;
		}
	}
	int q; cin >> q;
	int change = 0;
	while (q--)
	{
		int kind, col, x; cin >> kind >> col >> x;
		if (kind == 1)
		{
			change += x;
			f[col] += x;
		}
		if (kind == 2)
		{
			int dif = change - f[col];
			int l = 0, r = v[col].size() - 1;
			while (l < r)
			{
				int mid = (l + r) / 2;
				if (v[col][mid] + dif * (mid + 1) <= x) l = mid + 1;
				else r = mid - 1;
			}
			while (l > 0)
			{
				if (v[col][l - 1] + dif * l > x) l--;
				else break;
			}
			while (l < v[col].size())
			{
				if (v[col][l] + dif * (l + 1) <= x) l++;
				else break;
			}
			cout << l << '\n';
		}
	}

}