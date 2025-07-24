#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    int n; cin >> n;
    int ai;
    unordered_map <int,bool> f;
    for (int i=1;i<=n;i++)
    {
        cin >> ai;
        if (f.find(ai)==f.end())
        {
            cout << ai << ' ';
            f.insert({ai,true});
        }
    }
    cout << '\n';
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--) solve();
}
