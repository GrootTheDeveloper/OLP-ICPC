#include <bits/stdc++.h>
using namespace std;
#define int long long 


main()
{
	
	freopen("GAME.INP","r",stdin);
	freopen("GAME.OUT","w",stdout);
	int x,a,b,m,n; cin >> x >> a >> b >> m >> n;
	int res=0;
	for (int i=1;i<=x/a;i++)
	{
		if ((x-a*i)%b==0) res=max(res,i*m+((x-a*i)/b)*n);
	}	
	if (res==0) res=-1;
	cout << res;


}