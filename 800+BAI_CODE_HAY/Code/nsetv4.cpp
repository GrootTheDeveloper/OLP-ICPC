#include <bits/stdc++.h>
using namespace std;
#define int long long 


int dp[20][10][2], a[20];
int n, lim;
int bit[100005];
int b[100005], kind[100005], x[100005];
bool ok(int n)
{
	int lim = 0;
	while (n) a[++lim] = n % 10, n /= 10;
	for (int i = 1; i < lim; i++) 
		if (a[i] == 8 && a[i + 1] == 6) return true;
	return false;
}


int calc(int pos, bool lim, int cur, bool mask)
{
	if (pos < 1) return mask;
	if (!lim && dp[pos][cur][mask] != -1)
		return dp[pos][cur][mask];
	int res = 0;
	int mx = (lim? a[pos] : 9);
	for (int i = 0; i <= mx; i++)
		res += calc(pos - 1, lim && i == mx, i, mask || cur * 10 + i == 68);
	if (!lim) dp[pos][cur][mask] = res;
	return res;
}
int G(int x)
{
	n = 0;
	while (x) a[++n] = x % 10, x /= 10;
	return calc(n, true, 0, false);
}
void update(int idx, int val)
{
	for (; idx <= lim; idx += -idx&idx)
		bit[idx] += val;
}

int get(int l, int r)
{
	int ans = 0;
	l--;
	for (; r; r -= -r&r) ans += bit[r];
	for (; l; l -= -l&l) ans -= bit[l];
	return ans;
}

set <int> s;
unordered_map <int,int> zip;
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(dp, -1, sizeof(dp));
	int q; cin >> q;
	for (int i = 1; i <= q; i++)
	{
		cin >> kind[i] >> x[i];
		if (kind[i] == 1)
			s.insert(x[i]);
	}
	for (int c : s)
		zip[c] = ++lim, b[lim] = c;
	
	for (int i = 1; i <= q; i++)
	{
		if (kind[i] == 1)
		{
			if (ok(x[i]))
			{
				int pos = zip[x[i]];
				int c = get(pos, pos);
				if (c) update(pos, -1);
				else update(pos, 1);
			}else
			{
				int pos = zip[x[i]];
				int c = get(pos, pos);
				if (c) update(pos, 1);
				else update(pos, -1);
			}
		}
		else
		{
			int l = 1, r = 1e17;
			int ans;
			while (l <= r) 
			{
				int mid = (l + r) >> 1;
				int pos = upper_bound(b + 1, b + lim + 1, mid) - b - 1;
				int cnt = G(mid) - get(1, pos);
				if (cnt >= x[i]) ans = mid, r = mid - 1;
				else l = mid + 1;
			}
			cout << ans << '\n';
		}
	}

}