#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+7;
int t[N*4],a[N],f[N];

void up(int id, int l, int r, int pos, int val)
{
	if (pos>r || pos<l) return;
	if (l==r && l==pos) return t[id]=max(t[id],val),void();
	int mid=(l+r)/2;
	up(id*2,l,mid,pos,val);
	up(id*2+1,mid+1,r,pos,val);
	t[id]=max(t[id*2],t[id*2+1]);
}
int get(int id, int l, int r, int u, int v)
{
	if (u>r || v<l) return 0;
	if (u<=l && r<=v) return t[id];
	int mid=(l+r)/2;
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n; cin >> n;
	int res=0,s;
	while (n--)
	{
		cin >> s;
		for (int i=1;i<=s;i++) cin >> a[i];
		for (int i=1;i<=s;i++)
			f[i]=max(f[i],get(1,1,N-7,1,a[i])+a[i]);
		for (int i=1;i<=s;i++)
		{
			up(1,1,N-7,a[i],f[i]);
			res=max(res,f[i]);
			f[i]=0;
		}
	}
	cout << res;
}