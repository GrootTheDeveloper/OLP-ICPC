#include <bits/stdc++.h>
using namespace std;

long long bit[10][200005];
int n, q, a[200005];

void update(int id, int idx, int val)
{
    for (; idx <= n; idx += idx & -idx)
        bit[id][idx] += val;
}
long long get(int id, int idx1, int idx2)
{
    long long ans = 0;
    idx1--;
    for (; idx2; idx2 -= idx2 & -idx2)
        ans += bit[id][idx2];
    for (; idx1; idx1 -= idx1 & -idx1)
        ans -= bit[id][idx1];
    return ans;
}
bool check(int n, int i)
{
    if (n % i == 0) return true;
    while (n)
    {
        if (n % 10 == i) return true;
        n /= 10;
    }
    return false;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        update(0, i, a[i]);
        for (int x = 1; x <= 9; x++)
        if (check(i, x)) update(x, i, a[i]);
    }

    while (q--)
    {
        int kind; cin >> kind;
        if (kind == 1)
        {
            int pos, val; cin >> pos >> val;
            int change = val - a[pos];
            a[pos] = val;
            update(0, pos, change);

            for (int i = 1; i <= 9; i++)
            if (check(pos, i)) update(i, pos, change);

        } else
        {
            int l, r, k; cin >> l >> r >> k;
            long long ans = get(0, l, r);
            ans += get(k, l, r);
            cout << ans << '\n';
        }
    }
}
