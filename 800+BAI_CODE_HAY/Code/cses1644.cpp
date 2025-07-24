/*#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[200005];
multiset <int> s;
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,a,b;
    cin >> n >> a >> b;
    int res=-1e18;
    for (int i=1;i<=n;i++)
    {
        int ai;
        cin >> ai;
        f[i]=f[i-1]+ai;
    }
    for (int i=a; i<=n; i++)
    {
        if (i>b) s.erase(s.find(f[i-b-1]));
        s.insert(f[i-a]);
        res=max(res,f[i]-*s.begin());
    }
    cout << res;

}*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+7;
int f[N],t[N*4];

void build(int id, int l , int r)
{
    if (l==r) return t[id]=f[l],void();
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    t[id]=min(t[id*2],t[id*2+1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (l>v || r<u) return 1e18;
    if (u<=l && r<=v) return t[id];
    int mid=(l+r)/2;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,a,b; cin >> n >> a >> b;
    for (int i=1;i<=n;i++)
    {
        int ai; cin >> ai;
        f[i]=f[i-1]+ai;
    }
    build(1,1,n);
    int res=f[a]-f[0];
    for (int i=a+1;i<=n;i++)
    {
        if (i>=b)
            res=max({res,f[i]-f[i-b],f[i]-get(1,1,n,i-b,i-a)});
        else
            res=max({res,f[i]-get(1,1,n,1,i-a),f[i]-f[0]});
    }
    cout << res;
}

