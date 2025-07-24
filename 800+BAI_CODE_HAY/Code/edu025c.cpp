#include <bits/stdc++.h>
using namespace std;
#define int long long
int s,res=INT_MIN,mi;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("GIAODICH.INP","r",stdin);
	freopen("GIAODICH.OUT","w",stdout);
	int n,ai; cin >> n;
	for (int i=1;i<=n;i++)
	{
		cin >> ai;
		s+=ai;
		res=max(res,s-mi);
		mi=min(mi,s);
	}
	cout << res;
}