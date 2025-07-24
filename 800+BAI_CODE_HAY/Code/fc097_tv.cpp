#include <bits/stdc++.h>
using namespace std;

int choice[100005], hate_choice[100005], cnt[100005];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, p; cin >> n >> m >> p;
	for (int i = 1; i <= n; i++)
	{
		int x, y; cin >> x >> y;
		choice[i] = x;
		if (hate_choice[y] == 0) hate_choice[y] = i;
	}

	if (hate_choice[p] == 0) return cout << -1, 0;

	int ans = 0;
	while (hate_choice[p] != 0)
	{
		if (++cnt[hate_choice[p]] == 2) return cout << -1, 0;
		p = choice[hate_choice[p]];
		++ans;
	}
	cout << ans;
}