#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve()
{
	priority_queue <int> q;
	int n,k,x; cin >> n >> k;
	for (int i=1;i<=k;i++) cin >> x,q.push(x);
	int mouse=0,res=0;
	while (q.size())
	{
		int p=q.top();
		if (p>mouse) res++,mouse+=n-p,q.pop();
		else break;
	}
	cout << res << '\n';

}


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	while (t--) solve();
}