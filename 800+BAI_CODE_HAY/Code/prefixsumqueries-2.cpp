#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5,oo=-1e18;
int a[N],b[N],ai,t[N*4],lazy[N*4];
void push(int id)
{
    if (lazy[id])
    {
        t[id*2]+=lazy[id];
        t[id*2+1]+=lazy[id];
        lazy[id*2]+=lazy[id];
        lazy[id*2+1]+=lazy[id];
        lazy[id]=0;
    }
}
void build(int id, int l, int r)
{
    if (l==r) return t[id]=b[l],void();
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=max(t[id*2],t[id*2+1]);
}
void up(int id, int l, int r, int u, int v, int val)
{
    if (l>v||r<u) return;
    if (u<=l && r<=v)
    {
        t[id]+=val;
        lazy[id]+=val;
        return;
    }
    push(id);
    int mid=(l+r)/2;
    up(id*2,l,mid,u,v,val);
    up(id*2+1,mid+1,r,u,v,val);
    t[id]=max(t[id*2],t[id*2+1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (l>v || r<u) return oo;
    if (u<=l && r<=v) return t[id];
    push(id);
    int mid=(l+r)/2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,q; cin >> n >> q;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i]; b[i]=b[i-1]+a[i];;
    }
    build(1,1,n);
    while(q--)
    {
        int type,x,y;
        cin >> type >> x >> y;
        if (type==1) up(1,1,n,x,n,y-a[x]),a[x]=y;
        else
        {
            int t1=get(1,1,n,x,y);
            int t2=((x==1)? 0 : get(1,1,n,x-1,x-1));
            cout << max(t1-t2,0ll) << '\n';
        }
    }
}
