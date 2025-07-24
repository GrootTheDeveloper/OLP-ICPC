#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,k,x,y,a[N],b[N],lim,t[N*4];

void build(int id, int l, int r)
{
    if (l==r) return t[id]=b[l],void();
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=max(t[id*2],t[id*2+1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (l>v || r<u) return 0;
    if (u<=l && r<=v) return t[id];
    int mid=(l+r)/2;
    return max(get(id*2,l,mid,u,v) , get(id*2+1,mid+1,r,u,v));
}
void sub()
{
    int res=a[x]+b[y];
    lim=max(1LL,x-k);
    for (int i=x;i>=lim;i--)
    {
        int ans=a[i];
        int rot=x-i;
        ans+=get(1,1,n,max(y-k+rot,1LL),min(n,y+k-rot));
        res=max(res,ans);
    }
    lim=min(x+k,n);
    for (int i=x;i<=lim;i++)
    {
        int ans=a[i];
        int rot=i-x;
        ans+=get(1,1,n,max(y-k+rot,1LL),min(n,y+k-rot));
        res=max(res,ans);
    }
    cout << res;
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("L.INP","r",stdin);
    freopen("L.OUT","w",stdout);
    cin >> n >> k >> x >> y;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) cin >> b[i];
    build(1,1,n);
    if (k==0) return cout << a[x]+b[y],0;
    else if (k==1) return cout << max({a[x]+b[y],a[x+1]+b[y],a[x-1]+b[y],a[x]+b[y+1],a[x]+b[y-1]}),0;
    else sub();
}
