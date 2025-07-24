#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int MAX=2e5+5;
int a[MAX],seg[MAX*4],laz1[MAX*4],laz2[MAX*4];

void pull(int id, int l, int r)
{
	int mid=(l+r)/2;
	if (laz1[id])
	{
		seg[id*2] = laz1[id]*(mid-l+1);
		seg[id*2+1] = laz1[id]*(r-mid);
		laz1[id*2] = laz1[id];
		laz1[id*2+1] = laz1[id];
		laz2[id*2] = laz2[id*2+1] = 0;
		laz1[id] = 0;
	}
	if (laz2[id])
	{
		seg[id*2] += laz2[id]*(mid-l+1);
		seg[id*2+1] += laz2[id]*(r-mid);
		laz2[id*2] += laz2[id];
		laz2[id*2+1] += laz2[id];
		laz2[id]=0;
	}
}
void build(int id, int l, int r)
{
	if (l == r) return seg[id] = a[l],void();
	int mid = (l + r) / 2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
	seg[id] = seg[id*2] + seg[id*2+1];
}
void update1(int id, int l, int r, int u, int v, int x)
{
	if (l>v || r<u) return;
	if (u <= l && r <= v) 
	{
		seg[id]=(r-l+1)*x;
		laz2[id]=0;
		laz1[id]=x;
		return;
	}
	int mid = (l + r) /2;
	pull(id,l,r);
	update1(id*2,l,mid,u,v,x);
	update1(id*2+1,mid+1,r,u,v,x);
	seg[id] = seg[id*2] + seg[id*2+1];
}
void update2(int id, int l, int r, int u, int v, int x)
{
	if (l>v || r<u) return;
	if (u<=l && r<=v)
	{
		seg[id]+=(r-l+1)*x;
		laz2[id]+=x;
		return;
	}
	pull(id,l,r);
	int mid=(l+r)/2;
	update2(id*2,l,mid,u,v,x);
	update2(id*2+1,mid+1,r,u,v,x);
	seg[id] = seg[id*2] + seg[id*2+1];
}
int get(int id, int l, int r, int u, int v)
{
	if (l>v || r<u) return 0;
	if (u<=l && r<=v) return seg[id];
	pull(id,l,r);
	int mid=(l+r)/2;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);

}
signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,q; cin >> n >> q;
	for (int i=1;i<=n;i++) cin >> a[i];
	build(1,1,n);
	int type,u,v,x;
	while (q--)
	{
		cin >> type >> u >> v;
		if (type==3) cout << get(1,1,n,u,v) << '\n';
		else
		{
			cin >> x;
			if (type==1) update2(1,1,n,u,v,x);
			else update1(1,1,n,u,v,x);
		}
	}
}