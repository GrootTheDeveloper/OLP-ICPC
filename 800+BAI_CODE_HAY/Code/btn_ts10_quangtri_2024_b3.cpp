#include <bits/stdc++.h> 
using namespace std; 
#define int long long

unordered_map <int,bool> f;
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m; cin >> n >> m;
	int ai,bi;
	for (int i=1;i<=n;i++) cin >> ai,f.insert({ai,true});
	multiset <int> s;
	for (int i=1;i<=m;i++)
	{
		cin >> bi;
		if (f.find(bi)!=f.end()) s.insert(bi);
	}
	cout << s.size() << '\n';
	for (int i : s) cout << i << ' ';
}