#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int MAX=1e5+5;
int a[MAX],seg[MAX*4],lazy[MAX*4];

void pull(int id)
{
	if (lazy[id])
	{
		seg[id*2]+=lazy[id];
		seg[id*2+1]+=lazy[id];
		lazy[id*2]+=lazy[id];
		lazy[id*2+1]+=lazy[id];
		lazy[id]=0;
	}
}
void build(int id, int l, int r)
{
	if (l==r) return seg[id]=a[l],void();
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	seg[id]=max(seg[id*2],seg[id*2+1]);
}
void update(int id, int l, int r, int u, int v, int val)
{
	if (r<u || l>v) return;
	if (u<=l && r<=v)
	{
		seg[id]+=val;
		lazy[id]+=val;
		return;
	}
	pull(id);
	int mid=(l+r)/2;
	update(id*2,l,mid,u,v,val);
	update(id*2+1,mid+1,r,u,v,val);
	seg[id]=max(seg[id*2],seg[id*2+1]);
}
int get(int id, int l, int r, int u, int v)
{
	if (r<u || l>v) return 0;
	if (u<=l && r<=v) return seg[id];
	int mid=(l+r)/2;
	pull(id);
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

signed main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,q; cin >> n >> q;
	for (int i=1;i<=n;i++) cin >> a[i];
	build(1,1,n);
	while (q--)
	{
		int type,u,v,x;
		cin >> type >> u >> v;
		if (type==2) cout << get(1,1,n,u,v) << '\n';
		else
		{
			cin >> x;
			update(1,1,n,u,v,x);
		}
	}
}