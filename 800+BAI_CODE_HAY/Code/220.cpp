#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode = 1e9 + 7;

int cnt[50], a[22];
int power(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b&1) res = res * a % mode;
		a = a * a % mode;
		b >>= 1;
	}
	return res;
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	set <int> s;
	for (int i = 1, ai; i <= n; i++)
		cin >> ai, s.insert(ai), cnt[ai]++;
	int lim = 0;
	for (int x : s) a[++lim] = x;
	int MASK = (1 << lim) - 1;
	int ans = 0;
	for (int mask = 1; mask <= MASK; mask++)
	{
		int cur = 1, res = 1;
		for (int i = 0; i < lim; i++)
			if (mask >> i & 1)
			{
				if (k / cur < a[i + 1]) {res = 0; break;}
				cur *= a[i + 1];
				res = res * (power(2, cnt[a[i + 1]]) - 1) % mode;
				//cerr << cur << ' ';
			}
		ans += res;
		ans %= mode;
	}
	cout << ans;

}