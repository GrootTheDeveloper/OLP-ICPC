#include <bits/stdc++.h>
using namespace std;
#define int long long
int mask[100005];
bool prime[100005];
void init()
{
    for (int i = 2; i * i <= 1e5; i++)
        if (!prime[i]) for (int j = i * i; j <= 1e5; j += i) prime[j] = true;

    fill(mask + 1, mask + 100001, 1);
    for (int i = 2; i <= 1e5; i++)
        if (!prime[i]) for (int j = i; j <= 1e5; j+=i) mask[j] *= i;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans += (__gcd(i, j) == 1);
    cout << ans << ' ';


}
