#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> v;
int p[20], cnt_mark, lon[5000];
bool mark[20];

void check()
{
	int cnt = 0, val = 1;
	for (int i = 1; i <= cnt_mark; i++) if (mark[i])
		++cnt, val *= p[i];
	if (cnt)
	{
		v.push_back(val);
		lon[v.size() - 1] = cnt;
	}
}
void Try(int i)
{
	if (i > cnt_mark) return check(), void();
	for (int x = 0; x <= 1; x++)
		mark[i] = x, Try(i + 1);
}
void init(int n)
{
	int lim = (int)sqrt(n);
	for (int i = 2; i <= lim; i++)
	{
		if (n % i == 0)
		{
			p[++cnt_mark] = i;
			while (n % i == 0) n/=i;
		}
	}
	if (n != 1) p[++cnt_mark] = n;
	Try(1);
}
int _count_mask(int &l, int &r, int &n)
{
	return r / n - (l - 1) / n;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q; 
	init(n);
	while (q--)
	{
		int l, r; cin >> l >> r;
		int ans = 0;
		for (int i = 0; i < v.size(); i++)
			if (lon[i] & 1) ans += _count_mask(l, r, v[i]);
			else ans -= _count_mask(l, r, v[i]);
		cout << (r - l + 1) - ans << '\n';
	}

}