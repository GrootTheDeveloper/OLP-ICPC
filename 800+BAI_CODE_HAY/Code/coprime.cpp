#include <bits/stdc++.h>
using namespace std;
#define int long long 

int divs[500005];
int cnt_mark, mark[400005];
int lon[500005];
vector <int> d[500005];
bool k[500005];
bool check_mark(int n)
{
	int cnt = 0, m = n;
	while (n != 1)
	{
		int val = divs[n];
		if (n % (val * val) == 0) return false;
		n /= val;
		cnt++;
	}
	lon[m] = cnt;
	return true;
}
void init(int lim)
{
	for (int i = 2; i <= lim; i++) 
		if (divs[i] == 0) for (int j = i; j <= lim; j+=i)
			divs[j] = i;
	for (int i = 2; i <= lim; i++)
		if (check_mark(i)) mark[++cnt_mark] = i;
	
	for (int i = 1; i <= cnt_mark; i++)
	{
		int val = mark[i];
		for (int j = val; j <= lim; j += val) if (k[j]) d[j].push_back(val);
	}
}
bool us[500005];
int cnt[500005];
int a[500005];
int ans, S;
void add(int &n)
{
	int res = 0;
	for (int x : d[n])
	{
		if (lon[x] & 1) res += cnt[x];
		else res -= cnt[x];
		cnt[x]++;
	}
	ans += (S - res);
}
void del(int &n)
{
	int res = 0;
	for (int x : d[n])
	{
		if (lon[x] & 1) res += (cnt[x] - 1);
		else res -= (cnt[x] - 1);
		cnt[x]--;
	}
	ans -= (S - res);
}
void solve()
{
	int n, m; cin >> n >> m;
	int mx = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], mx = max(mx, a[i]), k[a[i]] = true;
	init(mx);
	while (m--)
	{
		int i; cin >> i;
		if (us[i] == 0)
		{
			add(a[i]);
			us[i] = true;
			S++;
		}
		else
		{
			S--;
			del(a[i]);
			us[i] = false;
		}
		cout << ans << '\n';
	}
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
}