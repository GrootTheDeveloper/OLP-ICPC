#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N],t[N*4],lazy[N*4];

void build(int id, int l, int r)
{
    if (l==r) return t[id]=a[l],void();
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    t[id]=t[id*2]+t[id*2+1];
}
void push(int id, int l, int r)
{
    int m=(l+r)/2;
    if (lazy[id])
    {
        t[id*2]+=(m-l+1)*lazy[id];
        t[id*2+1]+=(r-m)*lazy[id];
        lazy[id*2]+=lazy[id];
        lazy[id*2+1]+=lazy[id];
        lazy[id]=0;
    }
}
void up(int id, int l, int r, int u, int v, int val)
{
    if (l>v || r<u) return;
    if (u<=l && r<=v)
    {
        lazy[id]+=val;
        t[id]+=(r-l+1)*val;
        return;
    }
    push(id,l,r);
    int m=(l+r)/2;
    up(id*2,l,m,u,v,val);
    up(id*2+1,m+1,r,u,v,val);
    t[id]=t[id*2]+t[id*2+1];
}
int get(int id, int l, int r, int u, int v)
{
    if (l>v || r<u) return 0;
    if (u<=l && r<=v) return t[id];
    push(id,l,r);
    int m=(l+r)/2;
    return get(id*2,l,m,u,v)+get(id*2+1,m+1,r,u,v);
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q,m; cin >> m >> n >> q;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    build(1,1,n);
    while(q--)
    {
        int type;
        cin >> type;
        if (type==1)
        {
            int u,v,x;
            cin >> u >> v >> x;
            up(1,1,n,u,v,x);
        }
        else
        {
            int u,v;
            cin >> u >> v;
            cout << get(1,1,n,u,v)%m << endl;
        }
    }
}















