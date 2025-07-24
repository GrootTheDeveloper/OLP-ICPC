#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
int a[N],t[4*N],ai,l,r;
void build(int id, int l, int r)
{
    if (l==r) return t[id]=a[l],void();
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=max(t[id*2],t[id*2+1]);
}
int get(int id,int l, int r, int u, int v)
{
    if (l>v || r<u) return (int)-1e18;
    if (u<=l && r<=v) return t[id];
    int mid=(l+r)/2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n >> l >> r;
    for (int i=1;i<=n;i++) cin >> ai, a[i]=a[i-1]+ai;
    build(1,1,n);
    int res=-1e18;
    for (int i=1;i<=n-l+1;i++)
    {
        res=max(res,get(1,1,n,i+l-1,min(i+r-1,n))-a[i-1]);
    }
    cout << res;
}


