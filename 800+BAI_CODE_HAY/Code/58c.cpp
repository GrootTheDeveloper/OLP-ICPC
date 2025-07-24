#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+5;
int a[N],t[N*4];
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
	if (l==r && l==pos)
	{
		t[id]=a[pos];
		return;
	}
	int mid=(l+r)/2;
	up(id*2,l,mid,pos);
	up(id*2+1,mid+1,r,pos);
	t[id]=t[id*2]+t[id*2+1];
}
int get(int id, int l, int r, int u, int v)
{
	if (r<u || l>v) return 0;
	if (u<=l && r<=v) return t[id];
	int mid=(l+r)/2;
	return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("data.inp","r",stdin);
	freopen("data.out","w",stdout);
	int n,q; cin >> n >> q;
	for (int i=1;i<=n;i++) cin >> a[i];
	build(1,1,n);
	while (q--)
	{
		int type;
		cin >> type;
		if (type==3)
		{
			int T;
			cin >> T;
			continue;
		}
		if (type==1)
		{
			int u,v;
			cin >> u >> v;
			a[u]=v;
			up(1,1,n,u);
		}
		if (type==2)
		{
			int l,p,d;
			cin >> l >> p >> d;
			if (p==0) cout << a[l] << '\n';
			else if (d==1) cout << get(1,1,n,l,l+p*d) << '\n';
			else
			{
				int sum=a[l];
				while (p--)
				{
					l+=d;
					sum+=a[l];
				}
				cout << sum << '\n';
			}
		}

	}
}