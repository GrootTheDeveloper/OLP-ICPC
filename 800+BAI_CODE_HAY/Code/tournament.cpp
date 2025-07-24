#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2018 + 5;
const int mode = 1e9 + 7, mod = 2018;
long long h[N][N],f[N][N], g[N][N];
int a[N];
int n, q;

namespace sub1
{

	int C[N][N];
	void init()
	{
		for (int i = 0; i < N; i++)
			C[i][0] = 1;
		for (int i = 1; i < N; i++)
			for (int j = 1; j <= i; j++)
				C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
		memset(h, -1, sizeof(h));
	}
	int get(int p, int s)
	{
		if (h[p][s] != -1) return h[p][s];
		for (int i = 0; i <= s; i++) h[p][s] = 0;
		h[p][0] = 1;
		for (int i = 0; i <= s; i++)
		{
			h[p][s] += f[p - 1][i] * g[p + 1][s - i];
			h[p][s] %= mod;
		}
		return h[p][s];
	}
	void work()
	{
		init();
		for (int i = 0; i <= n + 1; i++)
			f[i][0] = g[i][0] = 1;
		for (int i = 1; i <= n; i++)	
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k <= min(a[i],  j / i); k++)
			{
				f[i][j] += (f[i - 1][j - k * i] * C[a[i]][k]);
				f[i][j] %= mod;
			}
		}
		for (int i = n; i >= 1; i--)
		for (int j = i; j <= n; j++)
		{
			for (int k = 0; k <= min(a[i], j / i); k++)
			{
				g[i][j] += g[i + 1][j - k * i] * C[a[i]][k];
				g[i][j] %= mod;
			}
		}

		while (q--)
		{
			int p, d, s; cin >> p >> d >> s;
			int ans = 0;
			for (int i = 0; i <= s / p; i++)
			{
				ans += get(p, s - p * i) * C[a[p] - d][i];
				ans %= mod;
			}
			cout << ans << '\n';
		}	
	}
}


namespace sub2
{
	int power(long long a, long long b)
	{
		long long res = 1;
		while (b)
		{
			if (b & 1) res = res * a % mode;
			a = a * a % mode;
			b >>= 1;
		}
		return res;
	}
	long long get(int p, int s)
	{
		if (h[p][s] != -1) return h[p][s];
		for (int i = 0; i <= s; i++) h[p][s] = 0;
		h[p][0] = 1;
		for (int i = 0; i <= s; i++)
		{
			h[p][s] += f[p - 1][i] * g[p + 1][s - i];
			h[p][s] %= mode;
		}
		return h[p][s];
	}

	void work()
	{
		for (int i = 0; i <= n + 1; ++i)
			f[i][0] = g[i][0] = 1;
		
		for (int i = 1; i <= n; ++i)	
		for (int j = 1; j <= n; ++j)
		{
			long long cur = 1;
			f[i][j] = f[i - 1][j];
			for (int k = 1; k <= min(a[i],  j / i); k++)
			{
				cur = (cur * (1LL * a[i] - k + 1) % mode) * power(k, mode - 2) % mode;
				f[i][j] += (f[i - 1][j - k * i] * cur);
				f[i][j] %= mode;
			}
		}

		for (int i = n; i >= 1; --i)
		for (int j = i; j <= n; ++j)
		{
			long long cur = 1;
			g[i][j] = g[i + 1][j];
			for (int k = 1; k <= min(a[i],  j / i); ++k)
			{
				cur = (cur * (1ll * a[i] - k + 1) % mode) * power(k, mode - 2) % mode;
				g[i][j] += g[i + 1][j - k * i] * cur;
				g[i][j] %= mode;
			}
		}
		

		memset(h, -1, sizeof(h));
		while (q--)
		{
			int p, d, s; cin >> p >> d >> s;
			long long cur = 1;
			long long ans = get(p, s);
			for (int i = 1; i <= min(a[p] - d,s / p); i++)
			{
				cur = (cur * (1ll * a[p] - d - i + 1) % mode) * power(i, mode - 2) % mode;	
				ans += get(p, s - p * i) * cur;
				ans %= mode;
			}
			cout << ans << '\n';
		}	
	}
}



signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("orangejuice.inp","r",stdin);
	freopen("orangejuice.out","w",stdout);
	int o; cin >> o;
	int MOD;
	cin >> n >> q >> MOD;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	if (MOD == 2018) sub1::work();
	else sub2::work();
}