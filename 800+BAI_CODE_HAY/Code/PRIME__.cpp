#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;
bool prime[1000006];
long long pre_pr[1000006], sum_pr[1000006];
int lef[1000006], rig[1000006], lim;

void sie()
{
	prime[1] = true;
	for (int i = 2; i <= 1e3; i++)
	if (!prime[i]) for (int j = i * i; j <= 1e6; j += i)
		prime[j] = true;

	for (int i = 2; i <= 1e6; i++)
		if (!prime[i]) lim++, pre_pr[lim] = i * lim, sum_pr[lim] = (sum_pr[lim - 1] + i) % mode;

	for (int i = 1; i <= lim; i++)
		pre_pr[i] += pre_pr[i - 1], pre_pr[i] %= mode;

	int tmp = 0;
	for (int i = 1; i <= 1e6; i++)
	{
		if (!prime[i]) tmp++;
		rig[i] = tmp + (prime[i]);
		lef[i] = tmp;
	}
}

void solve(int L, int R)
{
	int l = rig[L];
	int r = lef[R];
	if (l == 0 || r == 0) return cout << 0 << '\n', void();
	cout << (pre_pr[r] - pre_pr[l - 1] - 1ll * (l - 1) * (sum_pr[r] - sum_pr[l - 1]) + 1LL * mode * mode) % mode << '\n';
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	// freopen("test.inp","r",stdin);
	// freopen("test.out","w",stdout);
	sie();
	int t; cin >> t;
	while (t--)
	{
		int l, r; cin >> l >> r;
		solve(l, r);

		// long long ans = 0, cnt = 0;
		// for (int i = l; i <= r; i++)
		// 	if (!prime[i]) ans += i * (++cnt);
		// cout << ans % mode << '\n';
	}
}