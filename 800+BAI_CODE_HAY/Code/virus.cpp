#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7, MODE = mode * mode, base = 311;

string s, t;
int k, n, m;
int S[300005], T[300005], p[300005];
unordered_map <int,vector<int>> f;

int getT(int l, int r)
{
    return (T[r] - T[l - 1] * p[r - l + 1] + MODE) % mode;
}
int getS(int l, int r)
{
    return (S[r] - S[l - 1] * p[r - l + 1] + MODE) % mode;
}
void solve()
{
    for (int i = 1; i <= m - k; i++)
        f[getT(i + 1, i + k - 1)].push_back(i);
    vector <int> vec;
    for (int i = 1; i <= n - k; i++)
    {
        int Hash = getS(i + 1, i + k - 1);
        for (int x : f[Hash])
        {
            if (i < x) continue;
            int last = x + k;
            if (s[i] == t[x] || s[i + k] == t[last]) continue;
            if (i > 1 && x > 1)
            {
                int len = x - 1;
                if (getT(1, len) != getS(i - len, i - 1)) continue;
            }
            if (last < m && i + k < n)
            {
                int len = m - last;
                if (getT(last + 1, m) != getS(i + k + 1, i + k + len)) continue;
            }
            vec.push_back(i - x + 1);
        }
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), end(vec));
    cout << vec.size() << '\n';
    for (int i : vec) cout << i << ' ';
}
bool check(int x)
{
    vector <int> vec;
    for (int i = 1; i <= m; i++)
    {
        if (s[x] != t[i]) vec.push_back(i);
        x++;
    }
    if (vec.size() != 2) return false;
    return vec[1] - vec[0] == k;
}
int a[202];
int lim;
void sub2()
{
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * base % mode;
        S[i] = (S[i - 1] * base + s[i] - 'a' + 1) % mode;
        if (i <= m) T[i] = (T[i - 1] * base + t[i] - 'a' + 1) % mode;
    }
    solve();
}
void sub1()
{
    for (int i = 1; i + m - 1 <= n; i++)
        if (check(i)) a[++lim] = i;
    cout << lim << '\n';
    for (int i = 1; i <= lim; i++) cout << a[i] << ' ';

}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s >> t >> k;
    n    = s.size();
    m    = t.size();
    s    = " " + s;
    t    = " " + t;
    if (n <= 200 || k == 1) sub1();
    else sub2();
   //sub1(); cout << '\n'; sub2();

}
