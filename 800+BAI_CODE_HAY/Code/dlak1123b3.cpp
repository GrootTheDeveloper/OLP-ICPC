#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n <= 1e4)
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            set <int> s;
            for (int j = i; j <= n; j++)
            {
                s.insert(a[j]);
                if (s.size() > k) break;
                res += (s.size() == k);
            }
        }
        cout << res;
    }
}
