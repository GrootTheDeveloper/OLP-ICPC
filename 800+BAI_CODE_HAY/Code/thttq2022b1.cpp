#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[10000];
unordered_map <int,int> f,sol;
const int mode=1e9+7;
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n,q; cin >> n >> q;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++)
    {
        if (a[i]%q==0) f[a[i]]=f[a[i]/q]+1,sol[f[a[i]]]++;
        else f[a[i]]++;
    }
    for (int i=2;i<=n;i++) cout << sol[i]%mode;
}
