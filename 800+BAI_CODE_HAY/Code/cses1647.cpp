#include <bits/stdc++.h>
using namespace std;
#define maxn 200005
#define int long long
int a[maxn], t[maxn*4];

void build(int id, int l, int r)
{
    if (l==r) return t[id]=a[l],void();
    int mid = (l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=min(t[id*2],t[id*2+1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (l>v || r<u) return INT_MAX;
    if (u<=l && r<=v) return t[id];
    int mid = (l+r) /2;
    return min(get(id*2,l,mid,u,v), get(id*2+1,mid+1,r,u,v));
}
 main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,q,h,k;
    cin >> n >> q;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    build(1,1,n);
    while (q--)
    {
        cin >> h >> k;
        cout << get(1,1,n,h,k) << endl;
    }

}
