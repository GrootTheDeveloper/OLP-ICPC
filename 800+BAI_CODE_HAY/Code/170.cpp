#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int,int>
#define sz first
#define val second
const int mode = 1e9 + 7, base = 311, MODE = mode * mode;
string s, t;
int len, S[5555], T[5555], p[5555];
ii a[3];
int get(int l, int r)
{
    return (T[r] - T[l - 1] * p[r - l + 1] + MODE) % mode;
}
int getS(int l, int r)
{
    return (S[r] - S[l - 1] * p[r - l + 1] + MODE) % mode;
}
bool check(int l, int r)
{
    a[0].val = get(1, l);
    a[1].val = get(l + 1, r);
    a[2].val = get(r + 1, len);
    a[0].sz  = l;
    a[1].sz  = r - l;
    a[2].sz  = len - r;
    int d[3] = {0,1,2};
    do
    {
        int i = a[d[0]].sz, j = a[d[0]].sz + a[d[1]].sz;
        if (getS(1, i) == a[d[0]].val && getS(i + 1, j) == a[d[1]].val && getS(j + 1, len) == a[d[2]].val)
            return true;
    }while (next_permutation(d, d + 3));
    return false;
}
void solve()
{
    p[0] = 1;
    for (int i = 1; i <= len; i++)
    {
        p[i] = p[i - 1] * base % mode;
        T[i] = (T[i - 1] * base + t[i] - 'a' + 1) % mode;
        S[i] = (S[i - 1] * base + s[i] - 'a' + 1) % mode;
    }
    int res = 0;
    for (int i = 1; i < len; i++)
        for (int j = i + 1; j < len; j++)
            res += check(i, j);
    cout << res;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s >> t;
    len = s.size();
    s = " " + s;
    t = " " + t;
    solve();
}
