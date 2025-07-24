#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int n, q;
int a[500005];
int dp[500005], pre[500005], cnt[500005];

void sub1()
{
    int l, r; cin >> l >> r;
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
        cnt[i] = cnt[i - 1] + (s[i - 1] - '0');
    }
    for (int i = l; i <= r; i++)
    {
        dp[i] = dp[i - 1];
        for (int j = i; j >= l - 1; j--)
        {
            if (pre[i] - pre[j] >= 0 && cnt[i] - cnt[j] == 1)
            {
                dp[i] = max(dp[i], dp[j] + 1);
                break;
            }
        }
    }
    cout << *max_element(dp + l, dp + r + 1);
}

int nxt[500005], jum[500005];
void sub2()
{
    for (int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
        nxt[i] = (s[i - 1] == '1'? i : nxt[i - 1]);
        cnt[i] = cnt[i - 1] + (s[i - 1] - '0');
    }
    for (int i = 1; i <= n; i++) cout << nxt[i] << ' ';
    cout << '\n';
    int l, r; cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        int pos = nxt[i] - 1;
        if (pos < 0) continue;
        while (pre[i] - pre[pos] < 0 && pos >= l)
            pos = jum[pos];
        jum[i] = pos;
    }
    for (int i = 1; i <= n; i++) cout << jum[i] << ' ';
    cout << '\n';
    for (int i = l; i <= r; i++)
    {
        dp[i] = dp[i - 1];
        int pos = jum[i];
        if (cnt[i] - cnt[pos] == 1 && pos >= l - 1)
            dp[i] = max(dp[i], dp[pos] + 1);
    }
    cout << *max_element(dp + l + 1, dp + r + 1);
}






signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> s;
    if (q == 2)
    {
        int sum = 0;
        for (int i = 1; i <= 1e15; i++) sum += i;
        cout << sum;
    }
    if (q == 1 && n <= 5000) sub1();
//   else if (q == 1) sub2();
//    sub1(); cout << '\n';
//    memset(dp, 0, sizeof(dp));
//    memset(pre, 0, sizeof(pre));
//    memset(cnt, 0, sizeof(cnt));
//    sub2();
}
