#include <bits/stdc++.h>
using namespace std;
#define int long long 

int c1(const int &m, const int &n, const int &x, const int &y)
{
	return (m + n - 2) * x;
}

int c2(const int &m, const int &n, const int &x, const int &y)
{
	return (m - 1) * y + (n - m) * x;
}
int c3(const int &m, const int &n, const int &x, const int &y)
{
	int t1 = (m - 1) * y;
	int dic = n - m;
	if (dic & 1) return (dic - 1) * y + t1 + x;
	else return t1 + dic * y;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int m, n, x, y;
		cin >> m >> n >> x >> y;
		if (m > n) swap(m, n);
		if (m == 1) cout << (n - 1) * x << '\n';
		else cout << min({c1(m, n, x, y), c2(m, n, x, y), c3(m, n, x, y)}) << '\n';
	}
}