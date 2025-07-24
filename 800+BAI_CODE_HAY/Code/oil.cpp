#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000006];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, s; cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    priority_queue <int> q;
    for (int i = n; i >= 1; i--)
    {
        int B = -a[i] + s * i;
        if (q.size())
        {
            if (q.top() + B >= 0)
                ans += q.top() + B, q.pop();
        }
        q.push(a[i] - i * s);
    }
    cout << ans;
}
