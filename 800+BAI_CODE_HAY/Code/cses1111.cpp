#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode  = 1e9 + 7;
const int base = 311;
int n, k;
string s;
int T[5000006], BH[5000006], p[5000006];

int getR(int l, int r)
{
    return (T[r] - T[l - 1] * p[r - l + 1] + mode * mode) % mode;
}
int getL(int l, int r)
{
    return (BH[l] - BH[r + 1] * p[r - l + 1] + mode * mode) % mode;
}
bool check(int l, int r)
{
    return (getR(l, r) == getL(l, r));
}

int Proc(int pos)
{
    int l = 0, r = min(n - pos, pos - 1);
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(pos - mid, pos + mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans * 2 + 1;
}
int para(int pos1, int pos2)
{
    int l = 0, r = min(pos1 - 1, n - pos2);
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (check(pos1 - mid, pos2 + mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
    }
    return ans * 2 + 2;
}
void sub2()
{
    string st = " " + s;
    n = s.size();
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * base % mode;
        T[i] = (T[i - 1] * base + st[i]) % mode;
    }
    for (int i = n; i >= 1; i--)
        BH[i] = (BH[i + 1] * base + st[i]) % mode;

    int ans = 1;
    int pos = 1;
    for (int i = 1; i < n; i++)
    {
        int tmp = Proc(i);
        if (tmp > ans)
        {
            ans = tmp;
            pos = i - ans/2;
        }
        if (st[i] == st[i + 1])
        {
            int tmp = para(i, i + 1);
            if (tmp > ans)
            {
                ans = tmp;
                pos = i - ans / 2 + 1;
            }
        }
    }
    for (int i = pos; i <= pos + ans - 1; i++)
        cout << st[i];
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    sub2();
}
