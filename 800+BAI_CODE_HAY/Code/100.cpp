#include <bits/stdc++.h>
using namespace std;
#define int long long

unordered_map <int,int> f;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n,x; cin >> n >> x;
    int res = 0;
    for (int i = 1, ai; i <= n; i++) cin >> ai, res += f[x - ai], f[ai]++;
    cout << res;
}
