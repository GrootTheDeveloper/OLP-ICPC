#include <bits/stdc++.h>
using namespace std;
#define int long long
int pre[1000006], cnt_div[1000006];

void init()
{
    for (int i = 1; i <= 1e6; i++)
        for (int j = i; j <= 1e6; j += i) cnt_div[j]++;
    for (int i = 1; i <= 1e6; i++) pre[i] = pre[i - 1] + cnt_div[i];
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q; cin >> q;
    init();
    while (q--)
    {
        int l, r; cin >> l >> r;
        cout << pre[r] - pre[l - 1] << '\n';
    }
}
