#include <bits/stdc++.h>
using namespace std;
const int mode = 1e9 + 7;

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		long long ans = 0;
		for (char c : s)
			ans = (ans * 10 + (c - '0')) % mode;
		cout << (ans + 1) % mode << '\n';
	}
}