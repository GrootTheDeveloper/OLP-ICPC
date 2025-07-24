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
void sub1()
{
    string st = " ";
    for (int i = 1; i <= k; i++) st = st + s;
    p[0] = 1;
    for (int i = 1; i <= n * k; i++)
    {
        p[i] = p[i - 1] * base % mode;
        T[i] = (T[i - 1] * base + st[i]) % mode;
    }
    for (int i = n * k; i >= 1; i--)
        BH[i] = (BH[i + 1] * base + st[i]) % mode;

    int ans = 0;
    for (int i = 1; i <= n * k; i++)
        for (int j = i; j <= n * k; j++)
            if (check(i, j)) ans = max(ans, j - i + 1);
    cout << ans;
}

int Proc(int pos)
{
    int l = 0, r = min(n * k - pos, pos - 1);
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
    int l = 0, r = min(pos1 - 1, n * k - pos2);
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
    string st = " ";
    for (int i = 1; i <= k; i++) st = st + s;
    p[0] = 1;
    for (int i = 1; i <= n * k; i++)
    {
        p[i] = p[i - 1] * base % mode;
        T[i] = (T[i - 1] * base + st[i]) % mode;
    }
    for (int i = n * k; i >= 1; i--)
        BH[i] = (BH[i + 1] * base + st[i]) % mode;

    int ans = 1;
    for (int i = 1; i < n * k; i++)
    {
        ans = max(ans, Proc(i));
        if (st[i] == st[i + 1])
            ans = max(ans, para(i, i + 1));
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    cin >> s;
    if (n * k <= 4e3) sub1();
    else sub2();
//    sub1(); cout << '\n';
//    sub2();
}

