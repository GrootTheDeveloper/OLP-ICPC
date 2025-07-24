#include <bits/stdc++.h>
using namespace std;



signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if ((abs(a - c) & 1) || (abs(b - d) & 1)) return cout << -1, 0;
	cout << abs(a - c) / 2 + abs(b - d) / 2;
}