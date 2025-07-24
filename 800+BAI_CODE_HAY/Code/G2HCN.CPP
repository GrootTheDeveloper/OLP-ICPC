#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int u1, v1, u2, v2; cin >> u1 >> v1 >> u2 >> v2;
	int x = max(x1, u1), y = min(v1, y1);
	int u = min(x2, u2), v = max(v2, y2);
	int ans = (u - x) * (y - v);
	cout << (ans < 0? 0 : ans);
}