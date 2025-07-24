#include <bits/stdc++.h>
using namespace std;
#define int long long 
int a[20],f[20][20],n;

int calc(int i, bool lim, int cnt)
{
	if (i<1) return cnt<=3;
	if (lim==false && f[i][cnt]>=0) return f[i][cnt];
	int res=0;
	int mx=(lim? a[i]:9);
	for (int c=0;c<=mx;c++)
		res+=calc(i-1,lim && c==mx, cnt+(c!=0));
	if (!lim) f[i][cnt]=res;
	return res;
}

int g(int x)
{
	n=0;
	while (x) a[++n]=x%10,x/=10;
	return calc(n,true,0);
} 

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin >> t;
	memset(f,-1,sizeof(f));
	while (t--)
	{
		int l,r; cin >> l >> r;
		cout << g(r)-g(l-1) << '\n';
	}
}