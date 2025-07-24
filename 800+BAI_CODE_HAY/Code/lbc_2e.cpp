#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N],tmin[N*4],tmax[N*4];

void build(int id, int l, int r)
{
	if (l==r) return tmin[id]=a[l],tmax[id]=a[l],void();
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	tmin[id]=min(tmin[id*2],tmin[id*2+1]);
	tmax[id]=max(tmax[id*2],tmax[id*2+1]);
}
void up(int id, int l, int r, int u)
{
	if (u>r || u<l) return;
	if (l==r && l==u)
	{
		tmax[id]=a[u];
		tmin[id]=a[u];
		return;
	}
	int mid=(l+r)/2;
	up(id*2,l,mid,u);
	up(id*2+1,mid+1,r,u);
	tmin[id]=min(tmin[id*2],tmin[id*2+1]);
	tmax[id]=max(tmax[id*2],tmax[id*2+1]);
}
int getmax(int id, int l, int r, int u, int v)
{
	if (u>r || v<l) return INT_MIN;
	if (u<=l && r<=v) return tmax[id];
	int mid=(l+r)/2;
	return max(getmax(id*2,l,mid,u,v),getmax(id*2+1,mid+1,r,u,v));
}
int getmin(int id, int l, int r, int u, int v)
{
	if (u>r || v<l) return INT_MAX;
	if (u<=l && r<=v) return tmin[id];
	int mid=(l+r)/2;
	return min(getmin(id*2,l,mid,u,v),getmin(id*2+1,mid+1,r,u,v));
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,q; cin >> n >> q;
	for (int i=1;i<=n;i++) cin >> a[i];
	build(1,1,n);
	int type,u,v;
	while (q--)
	{
		cin >> type >> u >> v;
		if (type==1)
		{
			a[u]=v;
			up(1,1,n,u);
		}
		else cout << getmax(1,1,n,u,v)-getmin(1,1,n,u,v) << '\n';
	}
}