#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <int,int> f;
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int res=0;
    while (n--)
    {
        int ai; cin >> ai;
        res+=f[-ai];
        f[ai]++;
    }
    cout << res;
}
