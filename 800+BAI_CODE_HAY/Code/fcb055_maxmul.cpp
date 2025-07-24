#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=100005,mode=1e9+7;
int a[N],t[N*4],n,q;

void build(int id, int l, int r)
{
	if (l==r) return t[id]=a[l],void();
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	t[id]=(t[id*2]*t[id*2+1])%mode;
}
int get(int id, int l, int r, int u, int v)
{
	if (l>v || r<u) return 1LL;
	if (u<=l && r<=v) return t[id];
	int mid=(l+r)/2;
	return (get(id*2,l,mid,u,v)*get(id*2+1,mid+1,r,u,v))%mode;
}

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	build(1,1,n);
	cin >> q;
	while (q--)
	{
		int a,b;
		cin >> a >> b;
		cout << get(1,1,n,a,a+b-1) << '\n';
	}
}