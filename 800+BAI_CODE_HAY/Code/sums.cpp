#include <bits/stdc++.h>
using namespace std;
#define int long long
int pre[200005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, mode; cin >> n >> mode;
    int ans = 0, sum = 0;
    for (int i = 1; i <= n; i++)
    {
        char c; cin >> c;
        int x = c - '0';
        sum = sum * 10 + x * i;
        ans += sum;
        ans %= mode;
        sum %= mode;
    }
    cout << ans;
}
