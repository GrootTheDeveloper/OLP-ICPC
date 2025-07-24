#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=2e5+5;
int x[MAX],t[MAX*4];
void build(int id, int l, int r)
{
    if (l==r) return t[id]=x[l],void();
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=t[id*2]+t[id*2+1];
}
void update(int id, int l, int r, int pos)
{
    if (pos<l || pos>r) return;
    if (l==r) return t[id]=x[pos],void();
    int mid=(l+r)/2;
    update(id*2,l,mid,pos);
    update(id*2+1,mid+1,r,pos);
    t[id]=t[id*2]+t[id*2+1];
}
int get(int id, int l, int r, int u, int v)
{
    if (l>v || r<u) return 0;
    if (u<=l && r<=v) return t[id];
    int mid=(l+r)/2;
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,q; cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> x[i];
    build(1,1,n);
    int type,a,b,k,u;
    while (q--)
    {
        cin >> type;
        if (type==2)
        {
            cin >> a >> b;
            cout << get(1,1,n,a,b) << endl;
        }
        else
        {
            cin >> k >> u;
            x[k]=u;
            update(1,1,n,k);
        }
    }
}
