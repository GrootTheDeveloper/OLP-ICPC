#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int dp[20][10];
int a[20];
int calc(int pos, bool lim, bool zero, int last)
{
	if (pos < 1) return zero;
	if (!lim && dp[pos][last] != -1) return dp[pos][last];
	int res = 0;
	int mx = (lim? a[pos] : 9);
	for (int i = 0; i <= mx; i++)
	{
		if (last * 10 + i == 13 || i == 4) continue;
		res += calc(pos - 1, lim && i == mx, zero || (i != 0) , i);
	}
	if (!lim) dp[pos][last] = res;
	return res;
}


int g(int x)
{
	n = 0;
	while (x) a[++n] = x % 10, x /= 10;
	return calc(n, true, false, 0);
}

bool check(int n)
{
	string s = to_string(n);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '4') return true;
		if (i + 1 < s.size())
		{
			if (s[i] == '1' && s[i + 1] == '3') return true;
		}
	}
	return false;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x; cin >> x;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= x; i++)
		if (check(i)) cout << i << ' ';
	cout << '\n';
	for (int i = 1; i <= x; i++)
	{
		int a = g(i), b = g(i - 1);
		if (a - b == 0) cout << i << ' ';
	}
}



