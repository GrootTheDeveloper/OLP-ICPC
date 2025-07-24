#include <bits/stdc++.h>
using namespace std;
#define int long long 


main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	freopen("CANDIES.INP","r",stdin);
	freopen("CANDIES.OUT","w",stdout);
	int n,ai,cnt=0,back=0; cin >> n;
	while(n--)
	{
		cin >> ai;
		if (ai%3==0 && ai!=0) cnt++,back+=(ai/3 -1);
	}
	cout << cnt << '\n' << back;

}