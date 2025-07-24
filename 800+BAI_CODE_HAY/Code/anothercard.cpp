#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+3;
int a[N],t[N*4];
unordered_map <int,vector<int>> f;
void build(int id, int l, int r)
{
	if (l==r) return t[id]=a[l],void();
	int mid=(l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	t[id]=max(t[id*2],t[id*2+1]);
}
int get(int id, int l, int r, int u, int v)
{
	if (l>v || r<u) return INT_MIN;
	if (u<=l && r<=v) return t[id];
	int mid=(l+r)/2;
	return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}	

main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin >> n;
	for (int i=1;i<=n;i++) cin >> a[i];
	build(1,1,n);
	int sum=0,mi=0,res=0;
	f[0].push_back(0);
	for (int i=1;i<=n;i++)
	{
		sum+=a[i];
		for (int pos : f[mi])
			res=max(res,sum-mi-get(1,1,n,pos+1,i));
		mi=min(mi,sum);
		f[sum].push_back(i);

	}
	cout << res;	
}