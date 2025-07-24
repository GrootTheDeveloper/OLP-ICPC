#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N=5e4+2;
int dif[N],m,q;
pair <int,int> a[N];
void init()
{
    for (int i=2;i<=5e4;i++)
        if (!dif[i]) for (int j=i;j<=5e4;j+=i) dif[j]=i;
}
struct dta{
    vector <int> vi;
    unordered_map <int,int> f;
};
dta t[N*4];
dta fast(int n)
{
    dta res;
    vector <int> v;
    unordered_map <int,int> fa;
    while (n!=1)
    {
        if (fa[dif[n]]==0) v.push_back(dif[n]);
        fa[dif[n]]++;
        n/=dif[n];
    }
    res.vi=(v);
    res.f=(fa);
    return res;
}
dta mage(dta a, dta b)
{
    dta res;
    vector <int> v;
    unordered_map <int, int> fa;
    for (int c : a.vi)
    {
        if (fa[c]==0) v.push_back(c);
        fa[c]+=a.f[c];
    }
    for (int c : b.vi)
    {
        if (fa[c]==0) v.push_back(c);
        fa[c]+=b.f[c];
    }
    res.vi=(v);
    res.f=(fa);
    return res;
}
void build(int id, int l, int r)
{
    if (l==r) return t[id]=fast(l),void();
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=mage(t[id*2],t[id*2+1]);
}
dta oo;
dta get(int id, int l, int r, int u, int v)
{
    if (l>v || r<u) return oo;
    if (u<=l && r<=v) return t[id];
    int mid=(l+r)/2;
    return mage(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("J.INP","r",stdin);
    freopen("J.OUT","w",stdout);
    cin >> m >> q;
    init();
    int n=0;
    for (int i=1;i<=q;i++) cin >> a[i].fi >> a[i].se,n=max(n,a[i].se);
    build(1,1,n);
    for (int i=1;i<=q;i++)
    {
        dta rot=get(1,1,n,a[i].fi,a[i].se);
        int res=1;
        for (int c : rot.vi)
            res=(res*(rot.f[c]+1))%m;
        cout << res << '\n';
    }
}
