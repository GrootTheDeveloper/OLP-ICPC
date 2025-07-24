#include <bits/stdc++.h>
using namespace std;
#define int long long
/*map <int,int> f;
int a[500005];

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k; cin >> n >> k;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        f[a[i]]++;
        if (i>=k)
        {
            cout << f.begin() -> first << '\n';
            if (--f[a[i-k+1]]==0) f.erase(a[i-k+1]);
        }
    }
}*/
const int N=500005;
const int M=1e9;
int a[N],t[N*4];

void build(int id, int l, int r)
{
    if (l==r) return t[id]=a[l],void();
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=min(t[id*2],t[id*2+1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (l>v || r<u) return M;
    if (u<=l && r<=v) return t[id];
    int mid=(l+r)/2;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));

}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k; cin >> n >> k;
    for (int i=1;i<=n;i++) cin >> a[i];
    build(1,1,n);
    for (int i=1;i<=n-k+1;i++) cout << get(1,1,n,i,i+k-1) << '\n';
}
