#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int SIZE = 1e5+5;
int sum[SIZE*4],seg[SIZE*4],lazy1[SIZE*4],lazy2[SIZE*4],a[SIZE];
void down(int id, int l, int r)
{
	int mid=(l+r)/2;
	int x=lazy1[id],y=lazy2[id];
	if (lazy2[id]!=INT_MIN)
	{
		seg[id*2]=y*y*(mid-l+1);
		seg[id*2+1]=y*y*(r-mid);
		
		sum[id*2]=y*(mid-l+1);
		sum[id*2+1]=y*(r-mid);
		
		lazy2[id*2]=lazy2[id*2+1]=y;
		lazy1[id*2]=lazy1[id*2+1]=0;
		lazy2[id]=INT_MIN;
	}
	if (lazy1[id])
	{
		
		seg[id*2]+=x*x*(mid-l+1)+2*x*sum[id*2];
		seg[id*2+1]+=x*x*(r-mid)+2*x*sum[id*2+1];
		
		sum[id*2]+=(mid-l+1)*x;
		sum[id*2+1]+=(r-mid)*x;
		
		
		lazy1[id*2]+=x;
		lazy1[id*2+1]+=x;
		lazy1[id]=0;
	}
}
void build(int id, int l, int r)
{
	if (l==r) return seg[id]=a[l]*a[l],sum[id]=a[l],void();
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	seg[id]=seg[id*2]+seg[id*2+1];
	sum[id]=sum[id*2]+sum[id*2+1];
}
void update1(int id, int l, int r, int u, int v, int x)
{
	if (r<u || l>v) return;
	if (u<=l && r<=v)
	{
		lazy1[id]+=x;
		seg[id]+=(r-l+1)*x*x + 2*x*sum[id];
		sum[id]+=(r-l+1)*x;
		return; 
	}
	down(id,l,r);
	int mid=(l+r)/2;
	update1(id*2,l,mid,u,v,x);
	update1(id*2+1,mid+1,r,u,v,x);
	seg[id]=seg[id*2]+seg[id*2+1];
	sum[id]=sum[id*2]+sum[id*2+1];
}
void update2(int id, int l, int r, int u, int v, int x)
{
	if (r<u || l>v) return;
	if (u<=l && r<=v)
	{
		lazy2[id]=x;
		lazy1[id]=0;
		seg[id]=x*x*(r-l+1);
		sum[id]=x*(r-l+1);
		return; 
	}
	down(id,l,r);
	int mid=(l+r)/2;
	update2(id*2,l,mid,u,v,x);
	update2(id*2+1,mid+1,r,u,v,x);
	seg[id]=seg[id*2]+seg[id*2+1];
	sum[id]=sum[id*2]+sum[id*2+1];
}
int get(int id, int l, int r, int u, int v)
{
	if (r<u || l>v) return 0;
	if (u<=l && r<=v) return seg[id];
	int mid=(l+r)/2;
	down(id,l,r);
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,q; cin >> n >> q;
	for (int i=1;i<=n;i++) cin >> a[i];
	build(1,1,n);
	for (int i=1;i<=n*4;i++) lazy2[i]=INT_MIN;
		
	for (int type,u,v,x;q>0;q--)
	{
		cin >> type >> u >> v;
		if (type==2) cout << get(1,1,n,u,v) << '\n';
		else
		{
			cin >> x;
			if (type==1) update1(1,1,n,u,v,x);
			else update2(1,1,n,u,v,x);
		}
	}

}