#include <bits/stdc++.h>
using namespace std;
int cnt[30], odd[30];
int a[1111];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s; cin >> s;
		memset(cnt, 0, sizeof(cnt));
		for (char c : s)
			cnt[c - 'a']++;
		int mask = 0;
		for (int j = 0; j < 26; j++)
			if (cnt[j] & 1) mask = mask | (1 << j);
		a[i] = mask;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++)
		if (__builtin_popcount(a[i] ^ a[j]) <= 1) ans++;
	cout << ans;
}