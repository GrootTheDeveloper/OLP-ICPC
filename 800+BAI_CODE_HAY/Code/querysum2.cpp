#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=2e5+7;
int t[MAX*4],a[MAX],lazy[MAX*4];

void build(int id, int l, int r)
{
    if (l==r) return t[id]=a[l],void();
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=t[id*2]+t[id*2+1];
}
void push(int id, int l, int r)
{
    int mid=(l+r) >> 1;
    if (lazy[id]!=0)
    {
        t[id*2]+=1LL*(mid-l+1)*lazy[id];
        t[id*2+1]+=1LL*(r-(mid+1)+1)*lazy[id];
        lazy[id*2]+=lazy[id];
        lazy[id*2+1]+=lazy[id];
        lazy[id]=0;
    }
}
void upd(int id, int l, int r, int u, int v, int val)
{
    if (l>v || r<u) return;
    if (u<=l && r<=v)
    {
        lazy[id]+=val;
        t[id]+=1LL*(r-l+1)*val;
        return;
    }
    push(id,l,r);
    int mid=(l+r) >> 1;
    upd(id*2,l,mid,u,v,val);
    upd(id*2+1,mid+1,r,u,v,val);
    t[id]=t[id*2]+t[id*2+1];
}
int get(int id, int l, int r, int u, int v)
{
    if (l>v || r<u) return 0;
    if (u<=l && r<=v) return t[id];
    push(id,l,r);
    int mid=(l+r) >> 1;
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q;cin >> n >> q;
    for (int i=1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    int type,u,v,k;
    while (q--)
    {
        cin >> type;
        if (type==1)
        {
            cin >> u >> v >> k;
            upd(1,1,n,u,v,k);
        }
        else
        {
            cin >> u >> v;
            cout << get(1,1,n,u,v) << endl;
        }

    }
    return 0;

}
