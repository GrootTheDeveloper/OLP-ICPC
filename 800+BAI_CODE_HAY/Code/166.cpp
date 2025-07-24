#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7, base = 311;
int R[100005], L[100005], p[100005];
int getL(int l, int r)
{
    return (L[r] - L[l - 1] * p[r - l + 1] + mode * mode) % mode;
}
int getR(int l, int r)
{
    return (R[l] - R[r + 1] * p[r - l + 1] + mode * mode) % mode;
}
bool check(int x, int i)
{
    return getL(i, i + x) == getR(i - x, i);
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size();
    s = " " + s + " ";
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * base % mode;
        L[i] = (L[i - 1] * base + s[i] - 'a' + 1) % mode;
    }
    for (int i = n; i >= 1; i--)
        R[i] = (R[i + 1] * base + s[i] - 'a' + 1) % mode;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = 0, r = min(i, n - i);
        while (l < r)
        {
            int mid = l + r >> 1;
            if (check(mid, i)) l = mid + 1;
            else r = mid - 1;
        }
        while (check(l, i) && i + l <= n) l++;
        while (!check(l - 1, i)) l--;
        res += l;

        if (s[i] != s[i + 1]) continue;
        int a = i, b = i + 1;
        l = 0; r = min(a, n - b);
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (getR(a - mid, a) == getR(b, b + mid)) l = mid + 1;
            else r = mid - 1;
        }
        while (getR(a - l, a) == getL(b, b + l)) l++;
        while (getR(a - l + 1, a) != getL(b, b + l -1)) l--;
        res += l;
    }
    cout << res;
}
