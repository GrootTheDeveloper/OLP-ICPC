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
        h[p][s] = 0;
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

    int C[N][N];
    vector<int> v[N];
    int P[N], D[N], S[N];
    vector<int> b;

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
		if (h[p][s] >= 0) return h[p][s];
        h[p][s] = 0;
		for (int i = 0; i <= s; i++)
		{
			h[p][s] += f[p - 1][i] * g[p + 1][s - i];
			h[p][s] %= mode;
		}
		return h[p][s];
	}
    void init()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int c : v[i]) b.push_back(a[i] - c);
            b.push_back(a[i]);
        }
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());

        for (int l = 0; l < b.size(); l++)
        {
            int k = b[l];
            int cur = 1;
            C[l][0] = 1;
            for (int i = 1; i <= min(n, k); i++)
            {
                cur = (cur * (1ll * k - i + 1) % mode) * power(i, mode - 2) % mode;
                C[l][i] = cur;
            }
        }
    }
	void work()
	{
	    for (int i = 1; i <= q; i++)
            cin >> P[i] >> D[i] >> S[i], v[P[i]].push_back(D[i]);
        init();
		for (int i = 0; i <= n + 1; ++i)
			f[i][0] = g[i][0] = 1;

		for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
			f[i][j] = f[i - 1][j];
			for (int k = 1; k <= min(a[i],  j / i); k++)
			{
				f[i][j] += (f[i - 1][j - k * i] * C[pos][k]);
				f[i][j] %= mode;
			}
		}

		for (int i = n; i >= 1; --i)
		for (int j = i; j <= n; ++j)
		{
			int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
			g[i][j] = g[i + 1][j];
			for (int k = 1; k <= min(a[i],  j / i); ++k)
			{
				g[i][j] += g[i + 1][j - k * i] * C[pos][k];
				g[i][j] %= mode;
			}
		}


		memset(h, -1, sizeof(h));
		for (int e = 1; e <= q; e++)
        {
            int p = P[e], d = D[e], s = S[e];
            int pos = lower_bound(b.begin(), b.end(), a[p] - d) - b.begin();
			long long ans = get(p, s);
			for (int i = 1; i <= min(a[p] - d,s / p); i++)
			{
				ans += get(p, s - p * i) * C[pos][i];
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
