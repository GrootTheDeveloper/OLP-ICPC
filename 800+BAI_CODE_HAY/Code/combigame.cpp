#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct node
{
	int x, y;
	bool operator<(const node &other) const
	{
		return ((y == other.y)? x > other.x : y > other.y);
	}
}a[1005];


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].x >> a[i].y;
	sort(a + 1, a + n + 1);
	int res = a[1].x, nxt = a[1].y;
	for (int i = 2; i <= n; i++)
	{
		if (!nxt) break;
		nxt--;
		res += a[i].x;
		nxt += a[i].y;
	}
	cout << res;
}