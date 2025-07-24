#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+7;
int a[N],t[N*4],n,ai,f[100005];;

void build(int id, int l, int r)
{
    if (l==r) return t[id]=1,void();
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=t[id*2]+t[id*2+1];
}
void up(int id, int l, int r, int pos)
{
    if (pos<l || pos>r) return;
    if (l==r) return t[id]=0,void();
    int mid=(l+r)/2;
    up(id*2,l,mid,pos);
    up(id*2+1,mid+1,r,pos);
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
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++) cin >> ai,f[ai]=i;
    build(1,1,n);

    int l=1,r=n;
    while (l<=r)
    {
        cout << get(1,1,n,1,f[l])-1 << endl;
        up(1,1,n,f[l]);
        l++;
        if (r>=l) cout << get(1,1,n,f[r],n)-1 << endl;
        up(1,1,n,f[r]);
        r--;
    }
}
