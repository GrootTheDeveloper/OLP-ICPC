#include <bits/stdc++.h>
using namespace std;
#define int long long
multiset <int> s;
int n,k,ai;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> ai,s.insert(ai);
	int res=0;
	while (s.size())
	{
		auto i=s.end();
		i--;
		res+=*i;
		int val=*i;
		while (true)
		{
			auto it=s.upper_bound(val-k); 
			if (it!=s.begin())
			{
				it--;
				val=*it;
				s.erase(it);
			}
			else break;
		}
	}
	cout << res;
}