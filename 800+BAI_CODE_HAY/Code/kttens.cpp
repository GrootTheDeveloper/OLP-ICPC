#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

void bfs(string s, int n, unordered_map<string,int> & mp)
{
	mp[s] = 0;
	queue <string> q;
	q.push(s);
	while (q.size())
	{
		string u = q.front(); q.pop();
		if (mp[u] == 2) continue;
		int dis = mp[u];
		for (int x = 0; x <= n; x++)
			for (int y = x; y <= n; y++)
				for (int z = y; z <= n; z++)
				{
					string s1 = u.substr(0, x);
					string s2 = u.substr(x, y - x);
					string s3 = u.substr(y, z - y);
					string s4 = u.substr(z, n - z);
					string newS = s1 + s3 + s2 + s4;
					if (newS.size() != n) continue;
					if (mp.find(newS) == mp.end())
						mp[newS] = dis + 1, q.push(newS);
					else if (mp[newS] > x + 1)
						mp[newS] = dis + 1, q.push(newS);
					//cout << s1 << ' ' <<  s2  << ' ' <<  s3  << ' ' <<  s4 << '\n';
				}
	}
}

void solve()
{
	int n; cin >> n;
	string s1, s2;
	for (int i = 1; i <= n; i++)
	{
		int ai; cin >> ai;
		s1.push_back((char)('a' + ai - 1));
		s2.push_back((char)('a' + i - 1));
	}
	unordered_map <string, int> mp1, mp2;
	bfs(s1, n, mp1);
	bfs(s2, n, mp2);
	int ans = 5;
	for (auto x : mp1)
	{
		if (mp2.find(x.fi) != mp2.end())
			ans = min(ans, x.se + mp2[x.fi]);
	}
	cout << ans;
	if (ans == 5) cout << " or more";
	cout << '\n';
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	// string s = "abcdef";
	// cout << s.substr(0, 0);

	int t; cin >> t;
	 while (t--) solve();
}