#include <bits/stdc++.h>
using namespace std;
#define int long long 

vector <int> g[30];
int tin[30];
string a[222];
signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i < n; i++)
	{
		int id = 0, lim = min(a[i].size(), a[i + 1].size());
		while (id < lim)
		{
			if (a[i][id] != a[i + 1][id])
			{
				g[a[i + 1][id] - 'a'].push_back(a[i][id] - 'a');
				tin[a[i][id] - 'a']++;
				break;
			}
			id++;
		}
	}
	queue <int> q;
	for (char c = 'a'; c <= 'z'; c++) if (tin[c - 'a'] == 0) q.push(c - 'a');
	vector <char> vec;
	while (q.size())
	{
		int u = q.front(); q.pop();
		vec.push_back((char)(u + 97));
		for (int v : g[u])
			if (--tin[v] == 0) q.push(v);
	}
	if (vec.size() != 26) return cout << -1, 0;
	reverse(begin(vec), end(vec));
	for (char c : vec) cout << c;
}