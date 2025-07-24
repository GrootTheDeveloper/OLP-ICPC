#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> vi;

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m; cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		int ai; cin >> ai;
		vi.push_back(ai);
	}
	int res=0;
	for (auto it=vi.begin();it!=vi.end();it++)
	{
		auto its=upper_bound(vi.begin(),vi.end(),*it+m);
        res=max(res,1ll*(its-it)-1);
	}
	cout << res;
}
