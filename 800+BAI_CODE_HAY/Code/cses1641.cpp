#include <bits/stdc++.h>
using namespace std;
struct dt{
    int fi,se;
};
int a[5555];
dt f[5555];
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
    for (int i=1;i<=n-2;i++)
    {
        int l=i+1,r=n;
        while (l<r){
            int k=f[i].fi+f[l].fi+f[r].fi;
            if (k==x) return cout << f[i].se << ' ' << f[l].se << ' ' << f[r].se,0;
            if (k<x) l++;
            else r--;}
    }
    cout << "IMPOSSIBLE";
    return 0;
}
