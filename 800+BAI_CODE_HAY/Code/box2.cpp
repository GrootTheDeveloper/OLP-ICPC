#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
struct node
{
    int x, y, id;
    bool operator < (const node &other) const
    {
        return (x == other.x? y < other.y : x < other.x);
    }
}a[100005];
unordered_map <int, int> zip;
int lim;
vector <int> List[N];
int par[100005];
int seg[N * 4];
bool mark[100005];

void update(int id, int l, int r, int pos)
{
    if (pos > r || pos < l) return;
    if (l == r && pos == l)
    {
        if (List[pos].size() == 0) seg[id] = 0;
        else seg[id] = pos;
        return;
    }
    int mid = (l + r) >> 1;
    update(id * 2, l, mid, pos);
    update(id * 2 + 1, mid + 1, r, pos);
    seg[id] = max(seg[id * 2], seg[id * 2 + 1]);
}
int get(int id, int l, int r, int u, int v)
{
    if (u > r || v < l) return 0;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) >> 1;
    return max(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    set <int> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
        s.insert(a[i].x);
        s.insert(a[i].y);
    }
    for (int x : s)
        zip[x] = ++lim;
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        a[i].x = zip[a[i].x], a[i].y = zip[a[i].y];
    for (int i = 1; i <= n; i++)
    {
        int pos = get(1, 1, lim, 1,  a[i].y - 1);

        if (pos != 0)
        {
            par[i] = List[pos].back();
            List[pos].pop_back();
            update(1, 1, lim, pos);
        } else par[i] = i;

        if (a[i].x != a[i + 1].x)
        {
            int l = i;
            while (a[l].x == a[i].x)
                l--;
            for (int j = l + 1; j <= i; j++)
            {
                List[a[j].y].push_back(j);
                //cout << "(" << a[l].y << ' ' << l << ") ";
                update(1, 1, lim, a[j].y);
            }
        }
    }
    vector<vector<int>> ans;
    for (int i = n; i >= 1; i--)
    {
        if (!mark[i])
        {
            vector <int> temp = {i};
            int v = i;
            while (v != par[v])
            {
                temp.push_back(par[v]);
                v = par[v];
                mark[v] = true;
            }
            ans.push_back(temp);
        }

    }
    cout << ans.size() << '\n';
    for (auto x : ans)
    {
        cout << x.size() << ' ';
        for (auto val : x) cout << a[val].id << ' ';
        cout << '\n';
    }
}
