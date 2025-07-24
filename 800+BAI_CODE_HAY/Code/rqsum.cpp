#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7;
int a[N],t[N*4],lazy[N*4],type,u,v,val;

void push(int id, int l, int r)
{
	int mid=(l+r)/2;
	if (lazy[id])
	{
		lazy[id*2]+=lazy[id];
		lazy[id*2+1]+=lazy[id];
		t[id*2]+=(mid-l+1)*lazy[id];
		t[id*2+1]+=(r-mid)*lazy[id];
		lazy[id]=0;
	}
}

void build(int id, int l, int r)
{
	if (l==r) return t[id]=a[l],void();
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	t[id]=t[id*2]+t[id*2+1];
}
void up(int id, int l, int r, int u, int v, int val)
{
	if (u>r || v<l) return;
	if (u<=l && r<=v) 
	{
		t[id]+=(r-l+1)*val;
		lazy[id]+=val;
		return;
	}
	push(id,l,r);
	int mid=(l+r)/2;
	up(id*2,l,mid,u,v,val);
	up(id*2+1,mid+1,r,u,v,val);
	t[id]=t[id*2]+t[id*2+1];
}
int get(int id, int l, int r, int u, int v)
{
	if (u>r || v<l) return 0;
	if (u<=l && r<=v) return t[id];
	push(id,l,r);
	int mid=(l+r)/2;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,m; cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	build(1,1,n);
	while (m--)
	{
		cin >> type;
		if (type==1)
		{
			cin >> u >> v >> val;
			up(1,1,n,u,v,val);
		}
		else
		{
			cin >> u >> v;
			cout << get(1,1,n,u,v) << '\n';
		}
	}
}