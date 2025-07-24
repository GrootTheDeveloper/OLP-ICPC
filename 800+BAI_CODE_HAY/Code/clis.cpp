#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int n;
int a[500005];

struct node
    {
        int len, cnt;
        node friend operator + (node &a, node &b)
        {
            if (a.len < b.len) return b;
            if (b.len < a.len) return a;
            return (node){a.len, (a.cnt + b.cnt) % mode};
        }
    };
struct Segmentree
{
    vector <node> seg;
    int n;
    Segmentree (int _n)
    {
        n = _n;
        seg.assign(n * 4 + 5, (node){0, 0});
    }
    void update(int id, int l, int r, int pos, node val)
    {
        if (pos > r || pos < l) return;
        if (l == r && pos == l) return seg[id] = val, void();
        int mid = (l + r) >> 1;
        update(id * 2, l, mid, pos, val);
        update(id * 2 + 1, mid + 1, r, pos, val);
        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }
    node get(int id, int l, int r, int u, int v)
    {
        if (u > r || v < l) return (node){0, 0};
        if (u <= l && r <= v) return seg[id];
        int mid = (l + r) >> 1;
        node t1 = get(id * 2 + 1, mid + 1, r, u, v);
        node t2 = get(id * 2, l, mid, u, v);
        return (node){t1 + t2};
    }
    void update(int pos, node val)
    {
        update(1, 1, n, pos, val);
    }
    node get(int l, int r)
    {
        return get(1, 1, n, l, r);
    }
};

void sub1()
{
    vector<vector<int>> dp(n + 5, vector<int> (n + 5, 0));
    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][1] = 1;
        for (int j = i - 1; j >= 1; j--)
        if (a[i] > a[j])
        {
            for (int x = 1; x < n; x++)
                if (dp[j][x] != 0)
                    dp[i][x + 1] = (dp[i][x + 1] + dp[j][x]) % mode, len = max(len, x + 1);
                else break;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + dp[i][len]) % mode;
    cout << ans;
}
int b[500005];
void sub2()
{
    iota(b + 1, b + n + 1, 1);
    sort(b + 1, b + n + 1, [](int x, int y)
    {
        return (a[x] == a[y]? x > y : a[x] < a[y]);
    });
    Segmentree st(n);
    for (int i = 1; i <= n; i++)
    {
        int pos = b[i];
        node tmp = st.get(1, pos - 1);
        if (tmp.len == 0) tmp = (node){1, 1};
        else tmp.len++;
        st.update(pos, tmp);
    }
    cout << st.seg[1].cnt;

}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n <= 3e3) sub1();
    else sub2();
}
