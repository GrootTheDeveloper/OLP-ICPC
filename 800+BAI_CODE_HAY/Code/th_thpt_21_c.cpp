#include <bits/stdc++.h>
using namespace std;
#define int long long 
multiset <int> s;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0); 
	//freopen("bai3.inp","r",stdin);
	//freopen("bai3.out","w",stdout);
	int n,ai,k; cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> ai, s.insert(ai);
	int res=0;
	while (s.size())
	{
		int ans=0;
		auto it=s.begin();
		while (it!=s.end())
		{
			ans=(int)*it;
			s.erase(it);
			auto it2=s.lower_bound(ans+k);
			it=it2;
		}
		res+=ans;
	}
	cout << res;

}