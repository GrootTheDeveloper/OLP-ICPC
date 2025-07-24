#include <bits/stdc++.h>
using namespace std;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,u,v; cin >> n >> u >> v;
	int res=0,h,k;
	for (int i=u;i<=v;i++)
	{
		int r=min(n/(n/i),v);
		if (r-i+1>res) h=i,k=r,res=r-i+1,i=r;
	
	}
	cout << h <<  ' ' << k;
	return 0;

}
