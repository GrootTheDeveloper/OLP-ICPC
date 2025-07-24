#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7, base = 311;
int T[100005], p[100005];
int get(int l, int r)
{
    return (T[r] - T[l - 1] * p[r - l + 1] + mode * mode) % mode;
}
bool check(int l, int a, int b)
{
    return get(a, a + l) != get(b, b + l);
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        T[i] = (T[i - 1] * base + s[i] - '0' + 1) % mode;
        p[i] = p[i - 1] * base % mode;
    }
    int q; cin >> q;
    while (q--)
    {
        int a, b, x; cin >> a >> b >> x;
        int l = 0, r = x;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (check(mid, a, b)) r = mid - 1;
            else l = mid + 1;
        }
        while (check(l - 1, a, b) && l >= 1) l--;
        while (!check(l, a, b) && l <= x) l++;
        char res;
        if (l > x) res = '=';
        else
        {
            if (s[a + l] > s[b + l]) res = '>';
            else res = '<';
        }
        cout << res << '\n';
    }

}
