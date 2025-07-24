#include <bits/stdc++.h>
using namespace std;
#define sz(s) (int)s.size() 
const int mode = 1e9 + 7;

char a[1003];
string b[102];
int suf[1003], pre[1003];
void add(int &a, int b)
{
	a += b;
	if (a > mode) a -= mode;
}
int power(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = 1ll * res * a % mode;
		a = 1ll * a * a % mode;
		b >>= 1;
	}
	return res;
}

bool check(int pos, string &s)
{
	int l = 0;
	for (int i = pos; i <= pos + sz(s) - 1; i++)
	{
		if (a[i] != '?' && a[i] != s[l])
			return false;
		else l++;
	}
	return true;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	int m; cin >> m;
	for (int i = 1; i <= m; i++) cin >> b[i];

	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + (a[i] == '?');

	for (int i = n; i >= 1; i--)
		suf[i] = suf[i + 1] + (a[i] == '?');
	int ans = 0;
	for (int id = 1; id <= m; id++)
	{
		for (int i = 1; i <= n - sz(b[id]) + 1; i++)
		if (check(i, b[id])) 
			add(ans, 1ll * power(26, pre[i - 1]) * power(26, suf[i + sz(b[id])]) % mode);
	}
	cout << ans;
}