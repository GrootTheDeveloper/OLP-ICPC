#include <bits/stdc++.h>
using namespace std;
struct dt{
    int fi,se;
};
int a[1111];
dt f[1111];
bool cmp(dt a , dt b)
{
    return a.fi<b.fi;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,x; cin >> n >> x;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        f[i].fi=a[i];
        f[i].se=i;
    }
    sort(f+1,f+n+1,cmp);
    for (int i=1;i<=n-3;i++)
    {
        for (int j=i+1;j<=n-2;j++)
        {
            int l=j+1,r=n;
            while (l<r){
                int k=f[i].fi+f[j].fi+f[l].fi+f[r].fi;
                if (k==x) return cout << f[i].se << ' ' << f[j].se << ' ' << f[l].se << ' ' << f[r].se,0;
                if (k<x) l++;
                else r--;}
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}
