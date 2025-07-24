#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

struct node
{
    int ans0, ans1, pre1, pre0, suf1, suf0;
};
node seg[N * 4];
node oo;
int a[N * 4];
int n, q;
node join(node a, node b)
{
    node ans;
    ans.ans0 = max({a.ans0, b.ans0, a.suf0 + b.pre0});
    ans.suf0 = b.suf0;
    ans.pre0 = a.pre0;
    if (b.ans0 == b.suf0) ans.suf0 += a.suf0;
    if (a.pre0 == a.ans0) ans.pre0 += b.pre0;

    ans.ans1 = max({a.ans1, b.ans1, a.suf1 + b.pre1});
    ans.suf1 = b.suf1;
    ans.pre1 = a.pre1;
    if (b.ans1 == b.suf1) ans.suf1 += a.suf1;
    if (a.pre1 == a.ans1) ans.pre1 += b.pre1;
    return ans;
}
void update(int id, int l, int r, int pos, int val)
{
    if (pos < l || pos > r) return;
    if (l == r && pos == l)
    {
        seg[id].ans0 = seg[id].suf0 = seg[id].pre0 = (val == 0);
        seg[id].ans1 = seg[id].suf1 = seg[id].pre1 = (val == 1);
        return;
    }
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    seg[id] = join(seg[id * 2], seg[id * 2 + 1]);
}
node get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return oo;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    return join(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
int Find(int u, int v, int k, int x)
{
    int ans = -1;
    int l = u, r = v;
    int val;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        node temp = get(1, 1, n, u, mid);
        if (x == 0) val = temp.ans0; else val = temp.ans1;
        if (val >= k) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return ans;
}
int back_find(int u, int v, int k, int x)
{
    int ans = -1;
    int l = u, r = v;
    int val;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        node temp = get(1, 1, n, mid, v);
        if (x == 0) val = temp.ans0; else val = temp.ans1;
        if (val >= k) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        char x; cin >> x;
        a[i] = x - '0';
        update(1, 1, n, i, a[i]);
    }
    while (q--)
    {
        int kind; cin >> kind;
        if (kind == 1)
        {
            int pos, c; cin >> pos >> c;
            update(1, 1, n, pos, c);
        }
        if (kind == 2)
        {
            int L = 0, R = 0;
            int u, v, x, y; cin >> u >> v >> x >> y;

            int pos0 = Find(u, v, x, 0);
//            cout << pos0 << ' ';
            if (pos0 != - 1 && get(1, 1, n, u, pos0 - x).ans1 >= y)
            {
                int pos1 = back_find(u, pos0 - x, y, 1);
                pos0 = Find(pos1 + y, pos0, x, 0);
                node temp = get(1, 1, n, pos1, pos0);
                if (temp.ans0 == x && temp.ans1 == y) L = pos1, R = pos0;
            } if (L) {cout << L << ' ' << R << '\n'; continue;}
            if (pos0 != -1 && get(1, 1, n, pos0 + 1, v).ans1 >= y)
            {
                int pos1 = Find(pos0 + 1, v, y, 1);
                pos0 = back_find(pos0 - x + 1, pos1 - y, x, 0);
                node temp = get(1, 1, n, pos0, pos1);
                if (temp.ans0 == x && temp.ans1 == y) L = pos0, R = pos1;
            } if (L) {cout << L << ' ' << R << '\n'; continue;}
            cout << "-1" << '\n';

        }
    }
}
