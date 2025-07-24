#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[1000006];
signed main ()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	int plu=a[1],dec=0;
	for (int i=2,x,y;i<=n;i++)
	{
		x=plu;y=dec;
		plu=max(plu,y+a[i]);
		dec=max(dec,x-a[i]);
	}
	cout << max(dec,plu);
}