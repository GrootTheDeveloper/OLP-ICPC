#include <bits/stdc++.h>
using namespace std;
#define int long long
const int base = 31, mode = 1e9 + 7;
unordered_map <int,int> f;
int ans;
char a[11];
void solve(string &s)
{
	set <char> se;
	for (char c : s) se.insert(c);
	int n = - 1;
	for (auto x : se) a[++n] = x; 
	int mask = (1 << (n + 1));
	for (int msk = 1; msk <= mask; msk ++)
	{
		int Hash = 0, cnt = 0;
		for (int i = 0; i <= n; i++)
			if (msk & (1 << i)) Hash = Hash * base + a[i] - 'a' + 1, ++cnt;
		Hash %= mode;
		if (!cnt) continue;
		if (cnt & 1)
			ans += f[Hash]++;
		else 
			ans -= f[Hash]++;
		//cout << ans << ' ';
	}
	//cout << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string s; cin >> s;
		solve(s);
	}
	cout << ans;
}
// 7
// nohdk
// dd
// ea
// d
// lif
// fc
// kj
