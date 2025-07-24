#include <bits/stdc++.h>
using namespace std;

int Trie[2000006][26], cnt[2000006], exist[2000006], cur_pos;

void add(string &s)
{
	int pos = 0;
	for (char c : s)
	{
		if (Trie[pos][c - 'a'] == -1)
			Trie[pos][c - 'a'] = ++cur_pos;
		pos = Trie[pos][c - 'a'];
		cnt[pos]++;
	}
	exist[pos]++;
}
void counting_pre_of(string &s)
{
	int pos = 0;
	int ans = 0;
	for (char c : s)
	{
		if (Trie[pos][c - 'a'] == -1) break;
		pos = Trie[pos][c - 'a'];
		ans += exist[pos];
	}
	cout << ans << '\n';
}
void calc(string &s)
{
	int pos = 0;
	for (char c : s)
	{
		if (Trie[pos][c - 'a'] == -1)
			return cout << 0 << '\n', void();
		pos = Trie[pos][c - 'a'];
	}
	cout << cnt[pos] << '\n';
}
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> q;
	memset(Trie, -1, sizeof(Trie));
	while (q--)
	{
		int kind; string s;
		cin >> kind >> s;
		if (kind == 0) add(s);
		if (kind == 1) 	counting_pre_of(s);
		if (kind == 2) 	calc(s);
	}
}