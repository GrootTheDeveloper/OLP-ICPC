#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define fi first
#define se second
bool prime[32200];
int p[32000], x;
void init()
{
	int lim = 32000;
	for (int i = 2; i <= lim; i++)
		if (!prime[i]) 
		{
			p[++x] = i;
			for (int j = i * i; j <= lim; j+=i) prime[j] = true;
		}
}
void process(int n, unordered_map <int,int> &mp)
{
	for (int i = 1; i <= x && p[i] <= n; i++)
	{
		while (n % p[i] == 0)
		{
			mp[p[i]]++;
			n /= p[i];
		}
	}
	if (n != 1) mp[n]++;
}
int v[30];
void solve()
{
	int a, b; cin >> a >> b;
	//if (a > 50 && b > 50) return;
	unordered_map <int, int> mp;
	process(a, mp);
	process(b, mp);
	int n = 0;
	for (auto t : mp)
		if (t.se & 1) v[++n] = t.fi;
	//for (int i = 1; i <= n; i++) cout << v[i] << ' ';
	int MASK = (1 << n) - 1;
	long long X = a, Y = b;
	for (int mask = 0; mask <= MASK; mask ++)
	{
		long long x = 1, y = 1;
		for (int i = 0; i < n; i++)
			if (mask >> i & 1) x *= 1ll * v[i + 1];
			else y *= 1ll * v[i + 1];
		if (x + y < X + Y) X = x, Y = y;
	}
	cout << X << ' ' << Y << '\n';
	
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("minsum.inp","r",stdin);
	freopen("minsum.out","w",stdout);
	int t; cin >> t;
	init();
	while (t--) solve();

}