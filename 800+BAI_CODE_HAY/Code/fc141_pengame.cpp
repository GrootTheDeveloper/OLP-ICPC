#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;
int n, k, L, R;

int Find(int x)
{
	int l = 1, r = 1e6; 
	int ans = -1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (x + (k - 1) * mid > R) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	return ans;
}

void bup_pho_lo()
{
	int ans = 0;
	for (int i = L; i <= R; i++)
	{
		int x = Find(i);
		//cout << x << ' ';
		if (x == -1) continue;
		ans += (x - 1);
		ans %= mode;
	}
	cout << ans;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k >> L >> R;
	// if (k == 2) sub1();
	// else if (n <= 100 && k == 3) sub2();	
	bup_pho_lo();
}