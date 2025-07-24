#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <int, int> f;
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k; cin >> n >> k;
    int ai,res=0;
    for (int i=1;i<=n;i++)
    {
        cin >> ai;
        res+=f[k-ai];
        f[ai]++;
    }
    cout << res;
}
