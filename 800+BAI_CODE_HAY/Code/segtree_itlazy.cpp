#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7, oo=1e17;
int a[N],t[N*4],lz[N*4];

void push(int id, int l, int r)
{
    int m=(l+r)/2;
    if (lz[id])
    {
        lz[id*2]+=lz[id];
        lz[id*2+1]+=lz[id];
        t[id*2]+=lz[id];
        t[id*2+1]+=lz[id];
        lz[id]=0;
    }
}

void build(int id, int l, int r)
{
    if (l==r) return t[id]=a[l],void();
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=max(t[id*2],t[id*2+1]);
}

void up(int id, int l, int r, int u, int v, int val)
{
    if (l>v || r<u) return;
    if (u<=l && r<=v)
    {
        t[id]+=val;
        lz[id]+=val;
        return;
    }
    push(id,l,r);
    int mid=(l+r)/2;
    up(id*2,l,mid,u,v,val);
    up(id*2+1,mid+1,r,u,v,val);
    t[id]=max(t[id*2],t[id*2+1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (l>v || r<u) return -oo;
    if (u<=l && r<=v) return t[id];
    push(id,l,r);
    int mid=(l+r)/2;
    return max( get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    int q; cin >> q;
    while(q--)
    {
        int type; cin >> type;
        if (type==1)
        {
            int u,v,val;
            cin >> u >> v >> val;
            up(1,1,n,u,v,val);
        }
        else
        {
            int u,v;
            cin >> u >> v;
            cout << get(1,1,n,u,v) << endl;
        }
    }
}









