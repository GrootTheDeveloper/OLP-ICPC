#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define val first
#define id second

int n,p;
int seg[4000006];
struct Segmentree
{
    int n;
    Segmentree(int _n)
    {
        n = _n;
    }
    void up(int id, int l, int r, int pos)
    {
        if (pos > r || pos < l) return;
        if (l == r && l == pos) return seg[id] = 1, void();
        int mid =  (l + r) / 2;
        up(id * 2, l, mid, pos);
        up(id * 2 + 1, mid + 1, r, pos);
        seg[id] = seg[id * 2] + seg[id * 2 + 1];
    }
    int get(int id, int l, int r, int u, int v)
    {
        if (u > r || v < l) return 0;
        if (u <= l && r <= v) return seg[id];
        int mid = (l + r)/ 2;
        return get(id * 2, l, mid, u, v) + get(id * 2 + 1, mid + 1, r, u, v);
    }
    void up(int pos) { up(1,1,n,pos);}
    int get(int pos) { return get(1,1,n,1,pos);}
};

int a[1000005], pre[1000005];
ii fred[1000005];
bool cmp(ii a, ii b)
{
    return (a.val == b.val? a.id < b.id : a.val < b.val);
}
void sub1()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) res += ((pre[j] - pre[i - 1]) / (j - i + 1) >= p);
    cout << res;
}
void sub2()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        fred[i].val = fred[i - 1].val + (a[i] - p);
        fred[i].id  = i;
    }
   // for (int i = 1; i <= n; i++) cout << fred[i].val << ' ';
   // cout << '\n';
    sort(fred + 1, fred + n + 1, cmp);
    Segmentree st(n);
    for (int i = 1; i <= n; i++)
    {
        res += (fred[i].val >= 0);
        res += st.get(fred[i].id);
        st.up(fred[i].id);
    }
    cout << res;
}
signed main()
{
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = pre[i - 1] + a[i];
    cin >> p;
   // if (n <= 1e4) sub1();
   // else sub2();
 //  sub1();
   //cout << '\n';
   sub2();
}
