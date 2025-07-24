#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int dp[10004][22][20];
int n, a[10004];

int calc(int pos, bool lim, bool zero, int carry, int MASK)
{
    if (pos < 1) return (carry == 0 && zero);
    if (!lim && dp[pos][carry][MASK] != -1) return dp[pos][carry][MASK];
    int res = 0;
    int mx = (lim? a[pos] : 9);
    //cout << MASK << ' ';
    for (int i = 0; i <= mx; i++)
    {
        int newmask = MASK;
        if (zero || i != 0)
        {
            int tas = (i % 3);
            int mask = (tas == 0? 3 : tas);
            if (MASK >> (3 - tas) & 1) continue;
            newmask = (newmask | (1 << mask));
        }
        res = (res + calc(pos - 1, lim && (i == mx), (zero || i != 0),(carry * 10 + i) % 19, newmask)) % mode;
    }
    if (!lim) dp[pos][carry][MASK] = res;
    return res;
}
bool check(string n)
{
    int carry = 0;
    int MASK = 0;
    for (char c : n)
    {
        int val = c - '0';
        carry = (carry * 10 + val) % 19;
        int tas = (val % 3);
        int mask = (tas == 0? 3 : tas);
        if (MASK >> (3 - tas) & 1) return false;
        MASK = (MASK|(1 << mask));
    }
    return carry == 0;
}
int g(string x)
{
    n = 0;
    while (!x.empty()) a[++n] = x.back() - '0', x.pop_back();
    return calc(n, true,false, 0, 0);
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    memset(dp, -1, sizeof(dp));

    while (t--)
    {
        string l, r; cin >> l >> r;
        cout << (g(r)- g(l) + check(l) + mode * mode) % mode << '\n';
    }

}
//5
//1 10000
//1 100000
//1 1000000
//1000 1000000
//10000 200005
//63
//253
//920
//904
//289
