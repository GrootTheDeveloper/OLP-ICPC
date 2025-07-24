#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;

int seg[maxn * 4], a[maxn];

int comb(int pos1, int pos2)
{
    if (a[pos1] >= a[pos2]) return pos1;
    return pos2;
}

void build(int id, int l, int r)
{
    if (l == r) return seg[id] = l, void();
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    seg[id] = comb(seg[id * 2], seg[id * 2 + 1]);
}
void update(int id , int l, int r, int pos, int val)
{
    if (pos > r || pos < l) return;
    if (l == r && pos == l)
    {
        seg[id] = pos;
        a[l] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    seg[id] = comb(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) / 2;
    return comb(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("kgss.inp","r",stdin);
    freopen("kgss.out","w",stdout);
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = -100000;
    build(1, 1, n);
    int q; cin >> q;
    while (q --)
    {
        char type; int x,y;
        cin >> type >> x >> y;
        if (type == 'U')
            update(1,1,n,x,y);
        else
        {
            int pos1 = get(1,1,n,x,y);
            int pos2 = 0;
            if (pos1 > x) pos2 = comb(pos2, get(1,1,n,x,pos1-1));
            if (pos1 < y) pos2 = comb(pos2, get(1,1,n,pos1 + 1,y));
            cout << a[pos1] + a[pos2] << '\n';
        }
    }


}
