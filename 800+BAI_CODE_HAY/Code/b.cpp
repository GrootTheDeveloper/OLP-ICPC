#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
long long calc(int l, int r)
{
    return 1LL * (r + l) * (r - l + 1) / 2;
}

int n;
long long p;
int h;
vector <int> List[MAXN + 5];

long long tree[4 * (MAXN + 5)], lazy_sum[4 * (MAXN + 5)];
int lazy_cnt[4 * (MAXN + 5)];

void pushDown(int id, int l, int r, int mid)
{
    long long tmpSum = lazy_sum[id];
    int tmpCnt = lazy_cnt[id];
    lazy_sum[id] = lazy_cnt[id] = 0;
    
    tree[id * 2] += (mid - l + 1) * tmpSum - tmpCnt * calc(l, mid);
    lazy_sum[id * 2] += tmpSum;
    lazy_cnt[id * 2] += tmpCnt;
    
    tree[id * 2 + 1] += (r - mid) * tmpSum - tmpCnt * calc(mid + 1, r);
    lazy_sum[id * 2 + 1] += tmpSum;
    lazy_cnt[id * 2 + 1] += tmpCnt;
}

void Updata(int id, int l, int r, const int &u, const int &v, const int &sign)
{
    if (l > v || r < u) return;
    if (u <= l && r <= v)
    {
        tree[id] += sign * (1LL * (v + 1) * (r - l + 1) - calc(l, r));
        lazy_sum[id] += sign * (v + 1);
        lazy_cnt[id] += sign;
        return;
    }
    
    int mid = (l + r) / 2;
    pushDown(id, l, r, mid);
    Updata(id * 2, l, mid, u, v, sign);
    Updata(id * 2 + 1, mid + 1, r, u, v, sign);
    
    tree[id] = tree[id * 2] + tree[id * 2 + 1];
}

long long getSum(int id, int l, int r, const int &u, const int &v)
{
    if (l > v || r < u) return 0;
    if (u <= l && r <= v) return tree[id];
    
    int mid = (l + r) / 2;
    pushDown(id, l, r, mid);
    
    return getSum(id * 2, l, mid, u, v) + getSum(id * 2 + 1, mid + 1, r, u, v);
}

long long res = 0;

int par[MAXN + 5];
void initRoot(int n)
{
    memset(par + 1, -1, n * sizeof(int));
}

int root(int u)
{
    return (par[u] < 0 ? u : par[u] = root(par[u]));
}

void Merge(int u, int v)
{
    if ((u = root(u)) == (v = root(v))) return;
    Updata(1, 1, n, 1, -par[u], -1);
    Updata(1, 1, n, 1, -par[v], -1);
    
    if (par[v] < par[u]) swap(u, v);
    par[u] += par[v];
    par[v] = u;
    Updata(1, 1, n, 1, -par[u], 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("makeInput.inp", "r", stdin);
    freopen("b.out", "w", stdout);
    
    cin >> n >> p;
    for (int i = 1; i <= n; ++i)
    {
        cin >> h;
        List[h].push_back(i);
    }
    
    for (int i = MAXN; i >= 1; --i)
    {
        for (int idx : List[i])
        {
            par[idx] = -1;
            Updata(1, 1, n, 1, 1, 1);
            if (1 < idx && par[idx - 1] != 0) Merge(idx - 1, idx);
            if (idx + 1 <= n && par[idx + 1] != 0) Merge(idx, idx + 1);
        }
    
        int l = min(1LL * n + 1, (p - 1) / i + 1);
        res += getSum(1, 1, n, l, n);
    }
    
    cout << res;
    
    return 0;
}
