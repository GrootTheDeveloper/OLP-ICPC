#include  <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
int a[maxn],n,q,t[maxn*4],lazy[2][maxn];
int val(int x) {return x*(x+1)/2;}
void push(int id, int l, int r)
{
    int m=(l+r)/2;
    if (lazy[0][id])
    {
        t[id*2]+=val(m-l+1)*lazy[0][id];
        lazy[0][id*2]+=lazy[0][id];
        t[id*2+1]+=val(r-m)*lazy[0][id]+(m-l+1)*(r-m)*lazy[0][id];
        lazy[0][id*2+1]+=lazy[0][id];
        lazy[1][id*2+1]+=(m-l+1)*lazy[0][id];
        lazy[0][id]=0;

    }
    if (lazy[1][id])
    {
        t[id*2]+=lazy[1][id]*(m-l+1);
        lazy[1][id*2]+=lazy[1][id];
        t[id*2+1]+=lazy[1][id]*(r-m);
        lazy[1][id*2+1]+=lazy[1][id];
        lazy[1][id]=0;
    }
}
void build(int id, int l, int r)
{
    if (l==r) return t[id]=a[l],void();
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=t[id*2]+t[id*2+1];
}
void up(int id, int l, int r, int u, int v)
{
    if (v<l || r<u) return;
    if (u<=l && r<=v)
    {
        t[id]+=val(r-l+1)+(l-u)*(r-l+1);
        lazy[0][id]++;
        lazy[1][id]+=l-u;
        return;
    }
    push(id, l, r);
    int mid=(l+r)/2;
    up(id*2,l,mid,u,v);
    up(id*2+1,mid+1,r,u,v);
    t[id]=t[id*2]+t[id*2+1];
}
int get(int id, int l, int r, int u, int v)
{
    if (l>v || r<u) return 0;
    if (u<=l && r<=v) return t[id];
    push(id, l, r);
    int mid=(l+r)/2;
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int i=1;i<=n;i++)
        cin >> a[i];
    build(1,1,n);
    while (q--)
    {
        int type,u,v;
        cin >> type >> u >> v;
        if (type==1) up(1,1,n,u,v);
        else cout << get(1,1,n,u,v) << endl;
    }
}












