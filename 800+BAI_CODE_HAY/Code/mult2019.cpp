#include <bits/stdc++.h>
using namespace std;
const int mode = 2019;


void solve1(string &s)
{
	int n = s.size() - 1;
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int cur = 0;
		for (int j = i; j <= n; j++)
		{
			cur = (cur * 10 + s[j] - '0') % mode;
			ans += (cur == 0);
		}
	}
	cout << ans << ' ';
}

int cnt[3000];
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
void solve2(string &s)
{
	int n = s.size() - 1;
	int cur = 0, ans = 0;
	memset(cnt, 0, sizeof(cnt));
	cnt[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		cur = (cur + (s[i] - '0') * power(10, n - i)) % mode;
		ans += cnt[cur];
		cnt[cur]++;
	}
	cout << ans << '\n';

}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		s = " " + s;
		//solve1(s);
		solve2(s);
	}
}