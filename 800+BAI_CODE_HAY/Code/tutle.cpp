#include <bits/stdc++.h>
using namespace std;
#define int  long long 

int res,a[5],b[5];

void Try(int i)
{
	if (i==4)
	{
		res=min(res,abs(a[1]-a[2])+abs(a[1]-a[3])+abs(a[2]-a[3]));
		return;
	}
	for (int j=-1;j<=1;j++)
	{
		a[i]=b[i]+j;
		Try(i+1);
	}
}

void solve()
{
	res=(int)1e19;
	cin >> b[1] >> b[2] >> b[3];
	Try(1);
	cout << res << '\n';
}



main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int q; cin >> q;
	while (q--) solve();
}