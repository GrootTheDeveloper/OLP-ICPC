#include <bits/stdc++.h>
using namespace std;
int MAX=0;
struct dt
{
    vector<int> sol;
};
dt a[10];
struct dat
{
    int l,r,k;
};
dat f[(int)2e5+4];
int g(int n)
{
    int res=1;
    while (n!=0)
    {
        if (n%10!=0) res*=n%10;
        n/=10;
    }
    if (res<=9) return res;
    return g(res);
}
void sie()
{
    for (int i=1;i<=MAX;i++)
    {
        int k=g(i);
        a[k].sol.push_back(i);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int q; cin >> q;
    for (int i=1;i<=q;i++) cin >> f[i].l >> f[i].r >> f[i].k, MAX=max(MAX,f[i].r);
    sie();
    for (int i=1;i<=q;i++)
    {
        auto it1=lower_bound(a[f[i].k].sol.begin(),a[f[i].k].sol.end(),f[i].l);
        auto it2=upper_bound(a[f[i].k].sol.begin(),a[f[i].k].sol.end(),f[i].r);
        cout << it2-it1 << endl;
    }
    return 0;
}
