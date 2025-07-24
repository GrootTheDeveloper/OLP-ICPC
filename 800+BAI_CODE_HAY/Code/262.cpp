#include <bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 1e5 + 5;
struct node
{
    int l, r, idx;
}Q[N];
int bit[N], a[N], ans[N];
int n, q, S;

void update(int pos, int val)
{
    int idx = pos;
    while (idx <= n)
    {
        bit[idx] += val;
        idx += (idx&(-idx));
    }
}
int Get(int p)
{
    int ans = 0;
    while (p)
    {
        ans += bit[p];
        p -= (p&(-p));
    }
    return ans;
}
int get(int u, int v)
{
    return Get(v) - Get(u - 1);
}
long long Ans;
void add(int val, int heso, int wa)
{
    if (wa == 1)
    {
        if (heso == 1)
        {
            Ans += 1ll * get(val, n);
//cout << "R+ " << get(val, n) << '\n';
            update(val, 1);
        }
        else if (heso == -1)
        {
            update(val, -1);
            Ans -= 1ll * get(val, n);
//cout << "R- " << get(val, n) << '\n';
        }
        return;
    }
    if (heso == 1)
    {
        Ans += 1ll * get(1, val);
//cout << "L+ " << get(1, val) << '\n';
        update(val, 1);

    } else
    {
        update(val, -1);
        Ans -= 1ll * get(1, val);
//cout << "L- " << get(1, val) << '\n';
    }

}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= q; i++)
        cin >> Q[i].l >> Q[i].r, Q[i].idx = i;
    S = n / (int)sqrt(q);
    if (S == 0) S = n;
    sort(Q + 1, Q + q + 1, [](node &a, node&b)
        {
            if (a.l / S != b.l / S) return a.l < b.l;
            if ((a.l / S) & 1)
                return a.r > b.r;
            return a.r < b.r;
        });
    int l = 1, r = 0;
    for (int i = 1; i <= q; i++)
    {
        while (r < Q[i].r) add(a[++r], 1, 1);
        while (r > Q[i].r) add(a[r--], -1, 1);
        while (l < Q[i].l) add(a[l++], -1, -1);
        while (l > Q[i].l) add(a[--l], 1, -1);
        ans[Q[i].idx] = Ans;
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}

