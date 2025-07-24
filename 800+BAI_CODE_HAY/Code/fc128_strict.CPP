#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
unordered_map<int,int> f;
int a[200005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], f[a[i]]++;
    int ans = 0;
    for (auto x : f)
    {
        ans = ans + x.second * (ans + 1);
        ans %= mode;
    }
    cout << ans + 1;
}
