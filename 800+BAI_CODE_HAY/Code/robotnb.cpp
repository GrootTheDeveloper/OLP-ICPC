#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n, k, mid;

int calc(int x, int y)
{
	int jum = min(abs(x - mid), abs(y - mid));
	if (x < mid) x += jum;
	if (x > mid) x -= jum;
	if (y > mid) y -= jum;
	if (y < mid) y += jum;
	return jum * 15 + (abs(mid - x) + abs(mid - y)) * 10;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	mid = n / 2 + 1;
	int res = 0;
	for (int i = 1; i <= k; i++)
	{
		int x, y; cin >> x >> y;
		res += calc(x,y);
	}
	cout << res;
}