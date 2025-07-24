#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+7,oo=1e18;
int a[N],b[N],t[N*4],lz[N*4];

void push(int id)
{
    if (lz[id])
    {
        t[id*2]+=lz[id];
        t[id*2+1]+=lz[id];
        lz[id*2]+=lz[id];
        lz[id*2+1]+=lz[id];
        lz[id]=0;
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
    if (l>v || r<u) return;
    if (u<=l && r<=v)
    {
        t[id]+=val;
        lz[id]+=val;
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
    if (l>v || r<u) return -oo;
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
        cin >> a[i];
        b[i]=b[i-1]+a[i];
    }
    build(1,1,n);
    while (q--)
    {
        int type; cin >> type;
        if (type==1)
        {
            int k,u;
            cin >> k >> u;
            int val=u-a[k];
            a[k]=u;
            up(1,1,n,k,n,val);
        }
        else
        {
            int u,v; cin >> u >> v;
            int t1=get(1,1,n,u,v);
            int t2=get(1,1,n,u-1,u-1);
            if (t2!=-oo && t1-t2>=0)
                cout << t1-t2 << endl;
            else
                cout << 0 << endl;
        }
    }
}
