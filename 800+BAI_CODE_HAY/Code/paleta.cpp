#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 998244353;
int a[1000006], f[1000006];
int n, k;

void check(int &ans)
{
    for (int i = 1; i <= n; i++)
        if (f[i] != i && a[f[i]] == a[i]) return;
    ans++;
}
void Try(int i, int &ans)
{
    if (i > n) return check(ans), void();
    for (int x = 1; x <= k; x++)
        a[i] = x, Try(i + 1, ans);
}
void sub1()
{
    int ans = 0;
    Try(1, ans);
    cout << ans;
}
int power(int a, int b)
{
    int res = 1;
    while(b)
    {
        if (b&1) res = res * a % mode;
        a = a * a % mode;
        b >>= 1;
    }
    return res;
}
void sub2()
{
    cout << power(k, n);
}
int mul(int a, int b)
{
    int res = 0;
    while (b)
    {
        if (b&1) res = (res + a) % mode;
        a = (a + a) % mode;
        b >>= 1;
    }
    return res;
}
void sub3()
{
    struct DSU
    {
        vector <int> par, sz;
        DSU (int n)
        {
            par.resize(n + 1);
            sz.resize(n + 1);
            for (int i = 1; i <= n; i++)
                par[i] = i, sz[i] = 1;
        }
        int find(int v)
        {
            return (v == par[v]? v : par[v] = find(par[v]));
        }
        void Join(int a, int b)
        {
            a = find(a), b = find(b);
            if (a == b) return;
            if (sz[b] > sz[a]) swap(a, b);
            par[b] = a;
            sz[a] += sz[b];
        }
    };
    DSU d(n);
    for (int i = 1; i <= n; i++)
        d.Join(i, f[i]);
    int ans = 1;
    for (int i = 1; i <= n; i++)
    {
        int x = d.find(i);
        if (d.sz[x]) ans = mul(ans, k * power(k - 1, d.sz[x] - 1));
        d.sz[x] = 0;
    }
    cout << ans;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("paleta.inp","r",stdin);
    freopen("paleta.out","w",stdout);
    int o; cin >> o;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> f[i];
    if (o == 1) sub1();
    if (o == 2) sub2();
    if (o == 3 || o == 4) sub3();
    //sub1(); cout << ' '; sub3();
}
