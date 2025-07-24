#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+5;
struct Data
{
	int val=0,pos=0;
} tmin[N*4],tmax[N*4],p[N],oo;
int lazy[N],a[N],n,q;

Data ss(Data a, Data b, bool type)
{
	if (type)
	{
		if (a.val>b.val) return a;
		else return b;
	}
	else
	{
		if (a.val<b.val) return a;
		return b;
	}

}

void build(int id, int l, int r)
{
	if (l==r)
	{
		tmin[id]=tmax[id]=p[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	tmin[id]=ss(tmin[id*2],tmin[id*2+1],false);
	tmax[id]=ss(tmax[id*2],tmax[id*2+1],true);
}
void pull(int id)
{
	if (lazy[id])
	{
		tmin[id*2].val+=lazy[id];
		tmax[id*2].val+=lazy[id];
		tmin[id*2+1].val+=lazy[id];
		tmax[id*2+1].val+=lazy[id];
		lazy[id*2]+=lazy[id];
		lazy[id*2+1]+=lazy[id];
		lazy[id]=0;
	}
}
void up(int id, int l, int r, int u, int v, int val)
{
	if (u>r || v<l) return;
	if (u<=l && r<=v)
	{
		tmin[id].val+=val;
		tmax[id].val+=val;
		lazy[id]+=val;
		return;
	}
	pull(id);
	int mid=(l+r)/2;
	up(id*2,l,mid,u,v,val);
	up(id*2+1,mid+1,r,u,v,val);
	tmin[id]=ss(tmin[id*2],tmin[id*2+1],false);
	tmax[id]=ss(tmax[id*2],tmax[id*2+1],true);
}
Data get(int id, int l, int r, int u, int v)
{
	if (l>v || r<u) return oo;
	if (u<=l && r<=v) return tmin[id];
	int mid=(l+r)/2;
	pull(id);
	return ss(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v),false);
}
int k,x,val; 
void solve()
{
	cin >> k >> x;
	val=x-a[k];
	a[k]=x;
	up(1,1,n,k,n,val);
	int res = tmax[1].val-min(0LL,get(1,1,n,1,tmax[1].pos-1).val);
	cout << max(0LL,res) << '\n';
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> q;
	for (int i=1;i<=n;i++) 
	{
		cin >> a[i];
		p[i].val=p[i-1].val+a[i];
		p[i].pos=i;
	}
	oo.val=(int)1e18;
	build(1,1,n);

	while (q--) 
		solve();

}