#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define fi first
#define se second
const int mode = 1e9 + 7, base = 311, MODE = mode * mode;
int n, k, T[100005], p[100005];
string s;
void init()
{
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        T[i] = (T[i - 1] * base + s[i] - 'a' + 1) % mode;
        p[i] =  p[i - 1] * base % mode;
    }
}
int get(int l, int r)
{
    return (T[r] - T[l - 1] * p[r - l + 1] + MODE) % mode;
}
bool check(int x)
{
    int ans = 0;
    unordered_map <int, int> f;
    for (int i = 1; i <= n - x + 1; i++)
    {
        int Hash = get(i, i + x - 1);
        ans = max(ans, ++f[Hash]);
    }
    return ans >= k;

}

void solve()
{
    init();
    int l = 0, r = n, res = 0;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (check(mid)) l = mid + 1, res = mid;
        else r = mid - 1;
    }
    cout << res;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    s = " " + s;
    cin >> k;
    solve();
}
