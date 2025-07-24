#include <bits/stdc++.h>
using namespace std;
unordered_map <long long, int> cnt;
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int x, y; cin >> x >> y;
	string s; cin >> s;
	cnt[0] = 1;
	int a = 0, b = 0;
	long long ans = 0;
	for (char c : s)
	{
		a += (c == '0');
		b += (c == '1');
		ans += cnt[a * y - b * x]++;
	}
	cout << ans;
}