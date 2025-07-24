#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;

vector<int> d[N], Mask[N];
bool mark[N];
int cntmask[N];
int kind[100005], a[100005];
int divs[N];
long long ans, cnt[N], S;
void proc(int n)
{
    int x = n;
    while (n != 1)
    {
        int k = divs[n];
        while (n % k == 0) n /= k;
        d[x].push_back(k);
    }
    int lim = d[x].size();
    int MASK = (1 << lim) - 1;
    for (int mask = 1; mask <= MASK; mask++)
    {
        int s = 1;
        for (int i = 0; i < lim; i++)
            if (mask >> i & 1) s *= d[x][i];
        cntmask[s] = __builtin_popcount(mask);
        Mask[x].push_back(s);
    }
}
void init(const int &lim)
{
    for (int i = 2; i <= lim; i++)
    if (divs[i] == 0) for (int j = i; j <= lim; j += i) divs[j] = i;

    for (int i = 1; i <= lim; i++)
    if (mark[i]) proc(i);
}
void add(int val)
{
    long long res = 0;
    for (int mask : Mask[val])
    {
        if (cntmask[mask] & 1) res += cnt[mask];
        else res -= cnt[mask];
        cnt[mask]++;
    }
    ans += (S - res);
    S++;
}
void del(const int &val)
{
    long long res = 0;
    for (int mask : Mask[val])
    {
        if (cntmask[mask] & 1) res += cnt[mask];
        else res -= cnt[mask];
        cnt[mask]--;
    }
    ans -= (S - res);
    S--;

}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q; cin >> q;
    int lim = 0;
    for (int i = 1; i <= q; i++)
    {
        cin >> kind[i] >> a[i];
        if (kind[i] == 1) mark[a[i]] = true, lim = max(lim, a[i]);
    }

    init(lim);

    for (int i = 1; i <= q; i++)
    {
        if (kind[i] == 1) add(a[i]);
        else del(a[i]);
        cout << ans << '\n';
    }

}
