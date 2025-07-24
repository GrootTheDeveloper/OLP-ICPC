#include <bits/stdc++.h>
using namespace std;
#define int long long 


signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	for (int n,m; t; t--)
	{
		cin >> m >> n;
		vector <int> d[5];
		string s;
		for (int i = 1; i <= m; i++)
		{
			cin >> s;
			for (int j = 1; j <= n; ++j)
				switch (s[j-1])
				{
					case 'v':
						d[1].push_back(j);
						break;
					case 'i':
						d[2].push_back(j);
						break;
					case 'k':
						d[3].push_back(j);
						break;
					case 'a':
						d[4].push_back(j);
						break;
					default:
						break;
				}	 
		}
		for (int i = 1; i <= 4; i++)
		{
			sort(d[i].begin(),d[i].end());
			d[i].erase(unique(d[i].begin(),d[i].end()),end(d[i]));
		}
		int res = false;
		for (int c : d[1])
		{
			auto it = upper_bound(d[2].begin(),d[2].end(),c);
			if (it != d[2].end()) c = *it; else break;
			it = upper_bound(d[3].begin(),d[3].end(),c);
			if (it != d[3].end()) c = *it; else break;
			it = upper_bound(d[4].begin(),d[4].end(),c);
			if (it != d[4].end()) {res = true; break;}
		}
		cout << ((res) ? "YES":"NO") << '\n';
	}
}