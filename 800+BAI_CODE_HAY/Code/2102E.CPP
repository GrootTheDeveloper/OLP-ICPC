#include <bits/stdc++.h>
using namespace std;
const int jum = 1e6;

int cnt[2000006];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	long long ans = 0;
	int A = 0, B = 0;
	cnt[jum] = 1;
	for (char c : s)
	{
		A += (c == 'A');
		B += (c == 'B');
		ans += cnt[A - B + jum]++;
	}
	cout << ans;
}