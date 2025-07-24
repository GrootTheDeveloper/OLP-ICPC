#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,s,a[20],f[20][200];

int calc(int pos, bool lim, int sum)
{
	if (pos<1) return sum==s;
	if (lim==false && f[pos][sum]>=0) return f[pos][sum];
	int res=0;
	int mx=(lim? a[pos]:9);
	for (int c=0;c<=mx;c++)
		res+=calc(pos-1,lim && c==mx,sum+c);
	if (lim==false) f[pos][sum]=res;
	return res;
}
int G(int x)
{
	n=0;
	while (x)
	{
		a[++n]=x%10;
		x/=10;
	}
	return calc(n,true,0);
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int x,y; cin >> x >> y >> s;
	memset(f,-1,sizeof(f));
	int k=G(y)-G(x-1);
	cout <<  k << '\n';
	if (k==0) return cout << 0,0;
	int l=x,r=y,node=G(x-1);
	while (l<r)
	{
		int mid=(l+r)/2;
		if (G(mid)-node>=1) r=mid-1;
		else l=mid+1;
	}
	while (G(l-1)-node==1) l--;
	while (G(l)-node<1) l++;
	cout << l;

}