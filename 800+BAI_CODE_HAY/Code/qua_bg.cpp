#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
struct dta{int ai,val;};
dta a[N],t[N*4],f[N],oo;

dta ss(dta a, dta b)
{
    if (a.val>b.val) return a;
    else return b;
}

void up(int id, int l, int r, int pos)
{
    if (pos>r || pos<l) return;
    if (pos==l && l==r)
    {
        t[id]=f[pos];
        return;
    }
    int mid=(l+r)/2;
    up(id*2,l,mid,pos);
    up(id*2+1,mid+1,r,pos);
    t[id]=ss(t[id*2],t[id*2+1]);

}
dta get(int id, int l, int r, int u, int v, int lim)
{
    if (l==r && t[id].ai>=lim) return oo;
    if (r<u || l>v) return oo;
    if (u<=l && r<=v)
        if (t[id].ai<lim) return t[id];
    int mid=(l+r)/2;
    return ss(get(id*2,l,mid,u,v,lim),get(id*2+1,mid+1,r,u,v,lim));


}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i].ai >> a[i].val;
        if (i==1)
        {
            f[1]=a[1];
            up(1,1,n,1);
        }
        else
        {
            dta k=get(1,1,n,1,i-1,a[i].ai);
            f[i]=a[i];
            f[i].val+=k.val;
            up(1,1,n,i);

        }
    }
    cout << t[1].val;
}
