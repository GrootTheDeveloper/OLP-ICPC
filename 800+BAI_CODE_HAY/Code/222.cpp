#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n, l, r, a[22], ans;
bool mark[22];
int _count_mask(int x)
{
	return r / x - (l - 1 ) / x;
}

void check()
{
	int cnt = 0, val = 1;
	for (int i = 1; i <= n; i++) if (mark[i])
	{
		++cnt;
		if (r / val < a[i]) return;
		val = val * a[i];
	}
	if (cnt)
	{
		if (cnt & 1) ans += _count_mask(val);
		else ans -= _count_mask(val);
	}
}

void Try(int i)
{
	if (i > n) return check(), void();
	for (int x = 0; x <= 1; x++)
		mark[i] = x, Try(i + 1);
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> l >> r;
	set <int> s;
	for (int i = 1; i <= n; i++) cin >> a[i], s.insert(a[i]);
	n = 0;
	for (int x : s) a[++n] = x;
	Try(1);
	cout << ans;
}