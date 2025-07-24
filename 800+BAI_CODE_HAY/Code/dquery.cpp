#include <bits/stdc++.h>
using namespace std;
//#define int long long
int cnt[1000006], a[30004];
int Ans, S, ans[200005];
struct node
{
    int l, r, idx;
}query[200005];
void add(int val, int heso)
{
    if (heso == -1)
        Ans -= (--cnt[val] == 0);
    else
        Ans += (++cnt[val] == 1);
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int q; cin >> q;
    for (int i = 1; i <= q; i++)
        cin >> query[i].l >> query[i].r, query[i].idx = i;
    S = n / (int)sqrt(q);
    if (S == 0) S = n;
    sort(query + 1, query + q + 1, [](node a, node b)
         {
            if (a.l / S != b.l / S) return a.l < b.l;
            if ((a.l / S) & 1)
                return a.r > b.r;
            else
                return a.r < b.r;
         });
    int l = 1, r = 0;
    for (int i = 1; i <= q; i++)
    {
        while (r < query[i].r) add(a[++r], 1);
        while (r > query[i].r) add(a[r--], -1);
        while (l < query[i].l) add(a[l++], -1);
        while (l > query[i].l) add(a[--l], 1);
        ans[query[i].idx] = Ans;
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}
