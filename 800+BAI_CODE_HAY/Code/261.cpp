#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    int l, r, x, idx;
}Q[100005];
int a[100005], S, cnt[100005], Key[100005];

void add(int val, int heso)
{
    Key[cnt[val]]--;
    cnt[val] += heso;
    Key[cnt[val]]++;
}
int ans[100005];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= q; i++)
        cin >> Q[i].l >> Q[i].r >> Q[i].x, Q[i].idx = i;
    S = n / (int)sqrt(q);
    if (S == 0) S = n;
    sort(Q + 1, Q + q + 1, [](node a, node b)
         {
            if (a.l / S != b.l / S) return a.l < b.l;
            if ((a.l / S) & 1)
                return a.r > b.r;
            else
                return a.r < b.r;
         });
    int l = 1, r = 0;
    for (int i = 1; i <= q; i ++)
    {
        while (r < Q[i].r) add(a[++r], 1);
        while (r > Q[i].r) add(a[r--], -1);
        while (l < Q[i].l) add(a[l++], -1);
        while (l > Q[i].l) add(a[--l], 1);
        ans[Q[i].idx] = Key[Q[i].x];
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << ' ';

}
