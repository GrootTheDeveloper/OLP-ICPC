#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> g[100005];
int seg[N * 4];
int kind[N], a[N];
void update(int id, int l, int r, int pos, int val)
{
    if (pos > r || pos < l) return;
    if (l == r && pos == l) return seg[id] = val, void();
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos, val);
    update(id * 2 + 1, mid + 1, r, pos, val);
    seg[id] = __gcd(seg[id * 2], seg[id * 2 + 1]);
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> kind[i] >> a[i];
        if (kind[i] == 1) b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());

    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
        if (kind[i] == 1) update(1, 1, n, i, a[i]), g[pos].push_back(i);
        else
        {
            update(1, 1, n, g[pos].back(), 0);
            g[pos].pop_back();
        }
        cout << (seg[1] == 0? 1 : seg[1]) << '\n';
    }

}
