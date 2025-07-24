#include <bits/stdc++.h>
using namespace std;
int f[111];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int ai;
    for (int i=1;i<=n;i++) cin >> ai, f[ai]=1;
    int m,res=0; cin >> m;
    while (m--)
    {
        int k; cin >> k;
        int t=k;
        for (int i=1;i<=k;i++) cin >> ai, t-=f[ai];
        res+=(t==k);
    }
    return cout << res,0;
}
