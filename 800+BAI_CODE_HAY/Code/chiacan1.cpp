#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    int l, r, idx;
}query[200005];
int a[200005];
int ans[200005], Ans;
int cnt[1000006];
int S;
void add(int val)
{
    Ans -= cnt[val] * cnt[val] * val;
    cnt[val]++;
    Ans += cnt[val] * cnt[val] * val;
}
void del(int val)
{
    Ans -= cnt[val] * cnt[val] * val;
    cnt[val]--;
    Ans += cnt[val] * cnt[val] * val;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
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
        while (r < query[i].r) add(a[++r]);
        while (r > query[i].r) del(a[r--]);
        while (l < query[i].l) del(a[l++]);
        while (l > query[i].l) add(a[--l]);
        ans[query[i].idx] = Ans;
    }
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
}
