#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mode=1234567891;
unordered_map <int,int> f;
int a[1000006],b[1000006],n;
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("MMB.INP","r",stdin);
	freopen("MMB.OUT","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) cin >> b[i];

	for (int i=1;i<=n;i++)
	{
		int lef=0,rig=0;
		for (int l=i-1;l>=1;l--) 
			if (a[l]<=a[i]) lef++;else break;
		for (int r=i+1;r<=n;r++) 
			if (a[r]<=a[i]) rig++;else break;
		f[a[i]]+=(lef+rig+1)+(lef*rig);
	}
	int res=0;
	for (int i=1;i<=n;i++)
	{
		int lef=0,rig=0;
		for (int l=i-1;l>0;l--) 
			if (b[l]>=b[i]) lef++;else break;
		for (int r=i+1;r<=n;r++) 
			if (b[r]>=b[i]) rig++;else break;
		int t=(lef+rig+1)+(lef*rig);
		res=(res+(t%mode)*(f[b[i]]%mode)%mode)%mode; 
	}
	cout << res;

}