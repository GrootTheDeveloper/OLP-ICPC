#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 5;
int n, m, a[300000];
int seg[N * 4], lazy[N * 4];
struct Segmentree
{
    //vector <int> seg, lazy;
    int n, lim;
    Segmentree (int _n)
    {
        n = _n;
        lim = n;
        build(1, 1, n);
    }
    void push(int id)
    {
        if (lazy[id])
        {
            seg[id * 2] += lazy[id];
            seg[id * 2 + 1] += lazy[id];
            lazy[id * 2] += lazy[id];
            lazy[id * 2 + 1] += lazy[id];
            lazy[id] = 0;

        }
    }
    void build(int id, int l, int r)
    {
        if (l == r) return seg[id] = l, void();
        int mid = (l + r) >> 1;
        build(id * 2, l, mid);
        build(id * 2 + 1, mid + 1, r);
        seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
    }
    void update_set(int id, int l, int r, int pos)
    {
        if (l > pos || r < pos) return;
        if (l == r && pos == l) return seg[id] = -1, void();
        push(id);
        int mid = (l + r) >> 1;
        update_set(id * 2, l, mid, pos);
        update_set(id * 2 + 1, mid + 1, r, pos);
        seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
    }
    void asg(int id, int l, int r, int u, int v)
    {
        if (u > r || v < l) return;
        if (u <= l && r <= v)
        {
            seg[id] -= 1;
            lazy[id] -= 1;
            return;
        }
        push(id);
        int mid = (l + r) / 2;
        asg(id * 2, l, mid, u, v);
        asg(id * 2 + 1, mid + 1, r, u, v);
        seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
    }
    int get(int id, int l, int r, int u, int v)
    {
        if (u > r || v < l) return 0;
        if (u <= l && r <= v) return seg[id];
        int mid = (l + r) >> 1;
        push(id);
        return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    }
    int get(int pos)
    {
        return get(1,1,n,1,pos);
    }
    void asg(int l, int r)
    {
        asg(1,1,n,l,r);
    }
    void down(int pos)
    {
        update_set(1,1,n,pos);
    }
};
void sub1()
{
    int lim = n;
    for (int _ = 1; _ <= m; _ ++)
    {
        int pos; cin >> pos;
        if (pos > lim) {cout << 0 << '\n'; continue;}
        cout << a[pos] << '\n';
        lim--;
        for (int i = pos; i <= lim; i++) a[i] = a[i + 1];
    }
}

void sub2()
{
    Segmentree st(n);
    while (m--)
    {
        int pos; cin >> pos;
        if (pos > st.lim) {cout << 0 << '\n'; continue;}
        int l = 1, r = n;
        while (l < r)
        {
            int mid = (l + r) / 2;
            int val = st.get(mid);
            if (val >= pos) r = mid - 1;
            else l = mid + 1;
        }
        while (st.get(l) < pos) l++;
        while (st.get(l - 1) >= pos) l--;
        cout << l << '\n';
        st.asg(l + 1, n);
        st.down(l);
        st.lim--;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.inp","r",stdin);
    //freopen("output.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) a[i] = i;
    if (n <= 1e4) sub1();
    else sub2();
   // cout << '\n' << clock()/(double)1000 << " sec";
}
