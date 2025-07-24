#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt[100005];
int n, p;
string s;
int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b&1) res = (res * a) % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
void sub1()
{
    int ans = 0;
    s = " " + s;
    for (int i = 1; i <= n; i++)
        if ((s[i] - '0') % p == 0) ans += i;
    cout << ans << ' ';
}

void sub2()
{
    s = " " + s;
    int cur = 0, ans = 0;
    cnt[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int x = (s[i] - '0') * power(10, n - i) % p;
        cur = (cur + x) % p;
        ans += cnt[cur];
        cnt[cur]++;
    }
    cout << ans;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> p;
    cin >> s;
    if (p == 2 || p == 5) sub1();
    else sub2();
}
