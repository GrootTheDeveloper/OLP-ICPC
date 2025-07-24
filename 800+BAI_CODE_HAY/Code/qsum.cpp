#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+5;
int a[N],t[N*4],n,q;

void build(int id, int l, int r)
{
	if (l==r) return t[id]=a[l],void();
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	t[id]=t[id*2]+t[id*2+1];
}
void up(int id, int l, int r, int pos)
{
	if (pos>r || pos<l) return;
	if (l==r && pos==l) return t[id]=a[pos],void();
	int mid=(l+r)/2;
	up(id*2,l,mid,pos);
	up(id*2+1,mid+1,r,pos);
	t[id]=t[id*2]+t[id*2+1];

}
int get(int id, int l, int r, int u, int v)
{
	if (u>r || v<l) return 0;
	if (u<=l && r<=v) return t[id];
	int mid=(l+r)/2;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n >> q;
	for (int i=1;i<=n;i++) cin >> a[i];
	build(1,1,n);
	int type,u,v;
	while (q--)
	{
		cin >> type >> u >> v;
		if (type==1) a[u]+=v,up(1,1,n,u);
		else cout << get(1,1,n,u,v) << ' ';
	}
}