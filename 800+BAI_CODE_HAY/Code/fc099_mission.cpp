#include <bits/stdc++.h>
using namespace std;


int cur_pos, child[2000006][27], exist[2000006];

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	memset(child, -1, sizeof(child));
	int n; cin >> n;
	while (n--)
	{
		string s; cin >> s;
		int pos = 0;
		bool ok = false;
		string ans = "";
		for (char c : s)
		{
			if (!ok) ans.push_back(c);
			if (child[pos][c - 'a'] == -1)
				ok = true, child[pos][c - 'a'] = ++cur_pos;

			pos = child[pos][c - 'a'];
		}
		exist[pos]++;
		cout << ans;
		if (!ok) cout << ' ' << exist[pos];
		cout << '\n';
	}
		
}