#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k; cin >> n >> k;
    vector <int> f(k+1,0);
    for (int i=1;i<=n;i++)
    {
        int w,v;
        cin >> w >> v;
        for (int j=k;j>=w;j--)
            f[j]=max(f[j],f[j-w]+v);
    }
    cout << f[k];
}
