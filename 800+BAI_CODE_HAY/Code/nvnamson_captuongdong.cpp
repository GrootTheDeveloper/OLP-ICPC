#include <bits/stdc++.h>
using namespace std;
#define int long long

int divs[1000006], cnt[1000006];
void init()
{
    for (int i = 2; i <= 1e6; i++)
        if (!divs[i]) for (int j = i; j <= 1e6; j += i) divs[j] = i;
}
int mask(int n)
{
    int ans = 1;
    while (n != 1)
    {
        int k = divs[n];
        ans *= k;
        while (n % k == 0) n/=k;
    }
    return ans;
}
int comb(int n)
{
    return n * (n - 1) / 2;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int l, r; cin >> l >> r;
    init();
    for (int i = l; i <= r; i++)
        cnt[mask(i)]++;
    int ans = 0;
    for (int i = 1; i <= r; i++)
        if (cnt[i]) ans += comb(cnt[i]);
    cout << ans;
}
