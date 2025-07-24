#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
struct dta{ int pos,val;};
dta a[N],t[N*4],oo,t1,t2,t3;;
dta ss(dta a, dta b)
{
    if (a.val>b.val) return a;
    else return b;
}
void build(int id, int l, int r)
{
    if (l==r)
    {
        t[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=ss(t[id*2],t[id*2+1]);
}
dta get(int id, int l, int r, int u, int v)
{
    if (l>v || r<u) return oo;
    if (u<=l && r<=v) return t[id];
    int mid=(l+r)/2;
    return ss(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q; cin >> n >> q;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i].val;
        a[i].pos=i;
    }
    oo.val=INT_MIN;
    build(1,1,n);
    while (q--)
    {
        int x,y; cin >> x >> y;
        t1=get(1,1,n,x,y);
        if (t1.pos>x) t2=get(1,1,n,x,t1.pos-1);
        if (t1.pos<y) t3=get(1,1,n,t1.pos+1,y);
        cout << t1.val + ss(t2,t3).val << '\n';
        t2.val=t3.val=0;                                               
    }
}
