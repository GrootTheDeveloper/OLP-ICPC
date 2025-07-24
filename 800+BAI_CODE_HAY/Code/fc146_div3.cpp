#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt[3];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    while (n) cnt[(n%10)%3]++, n/=10;
    cnt[1] %= 3;
    cnt[2] %= 3;
    int tmp = min(cnt[1], cnt[2]);
    cnt[1] -= tmp, cnt[2] -= tmp;
    cout << max(cnt[1], cnt[2]);
}
