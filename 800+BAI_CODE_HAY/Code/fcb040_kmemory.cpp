#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+1;
int mi[N*4],ma[N*4],a[N],n,k;
void build(int id, int l, int r)
{
	if (l==r) return mi[id]=ma[id]=a[l],void();
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	mi[id]=min(mi[id*2],mi[id*2+1]);
	ma[id]=max(ma[id*2],ma[id*2+1]);
}

int getmin(int id, int l, int r, int u, int v)
{
	if (l>v || r<u) return INT_MAX;
	if (u<=l && r<=v) return mi[id];
	int mid=(l+r)/2;
	return min(getmin(id*2,l,mid,u,v), getmin(id*2+1,mid+1,r,u,v));
}
int getmax(int id, int l, int r, int u, int v)
{
	if (l>v || r<u) return INT_MIN;
	if (u<=l && r<=v) return ma[id];
	int mid=(l+r)/2;
	return max(getmax(id*2,l,mid,u,v), getmax(id*2+1,mid+1,r,u,v));
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	cin >> n >> k;
	for (int i=1;i<=n;i++) cin >> a[i];
	build(1,1,n);
	int l=1,res=0;
	for (int r=1;r<=n;r++)
	{
		while (getmax(1,1,n,l,r)-getmin(1,1,n,l,r)>k) l++;
		res+=(r-l+1);
	}
	cout << res;
}