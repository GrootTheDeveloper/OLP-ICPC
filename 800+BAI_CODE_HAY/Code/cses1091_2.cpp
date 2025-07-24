#include <bits/stdc++.h>
using namespace std;
#define int long long 
int ai;
multiset <int> s;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m; cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> ai;
		s.insert(-ai);
	}
	while (m--)
	{
		cin >> ai;
		auto it=s.lower_bound(-ai);
		if (it==s.end())
		{
			cout << -1 << '\n';
			continue;
		}
		cout << -(*it) << '\n';
		s.erase(it);
	}
}