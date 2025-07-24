#include <bits/stdc++.h>
using namespace std;
#define int long long
int ai;
multiset <int> s;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) 
	{
		cin >> ai;
		s.insert(ai);
		auto it=s.lower_bound(ai);
		it++;
		if (it!=s.end()) s.erase(it);
	}
	cout << s.size();
}