#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=200005;
int x[MAX],t[MAX*4],lazy[MAX*4];
void update(int id, int l, int r, int u, int v, int k)
{
    if(l>v || r<u) return;
    if(u<=l && r<=v)
    {
        t[id]+=k;
        lazy[id]+=k;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v,k);
    update(id*2+1,mid+1,r,u,v,k);
    t[id]=t[id*2]+t[id*2+1]+lazy[id];
}
int get(int id, int l, int r, int u, int v)
{
    if(l>v || r<u) return 0;
    if (u<=l && r<=v) return t[id];
    int mid=(l+r)/2;
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v)+lazy[id];
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,q;cin >> n >> q;
    for (int i=1;i<=n;i++) cin >> x[i];
    int type,k,a,b,u;
    while (q--)
    {
        cin >> type;
        if (type==2)
        {
            cin >> k;
            cout << x[k]+get(1,1,n,k,k) <<"\n";
        }
        else
        {
            cin >> a >> b >> u;
            update(1,1,n,a,b,u);
        }

    }
    return 0;

}
