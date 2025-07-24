#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;
int lis[1000], lim;
int gt[100005];
int cnt[100005], pre[100005];
int power(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b&1) res = res * a % mode;
        a = a * a % mode;
        b >>= 1;
    }
    return res;
}

int C(int n, int k)
{
    return gt[n] * power(gt[k] * gt[n - k] % mode, mode - 2) % mode;
}

void init()
{
    for (int i = 3; i * i <= 7e5; i++)
        lis[++lim] = i * i;
    gt[0] = 1;
    for (int i = 1; i <= 1e5; i++)
        gt[i] = gt[i - 1] * i % mode;

    for (int i = 1; i <= 1e5; i++)
    {
        int pos1 = lower_bound(lis + 1, lis + lim + 1, i * 3) - lis;
        int pos2 = upper_bound(lis + 1, lis + lim + 1, i * 7) - lis - 1;
        for (int j = pos1; j <= pos2; j++)
        {
            if ((lis[j] - 3 * i) % 4 == 0)
            {
                int k = (lis[j] - 3 * i) / 4;
                if (k > i) continue;
                cnt[i] = (cnt[i] + C(i, k)) % mode;
            }
        }
    }
    for (int i = 1; i <= 1e5; i++)
        pre[i] = (pre[i - 1] + cnt[i]) % mode;

}
int mlem(int n, int sum, int Size)
{
    int ans = 0;
    int pos1 = lower_bound(lis + 1, lis + lim + 1, Size * 3) - lis;
    int pos2 = upper_bound(lis + 1, lis + lim + 1, Size * 7) - lis - 1;
    for (int i = pos1; i <= pos2; i++)
    {
        if ((lis[i] - sum - n * 3) % 4 == 0 && (lis[i] - sum - n * 3 >= 0))
        {
            int k = (lis[i] - sum - n * 3) / 4;
            if (k > n) continue;
            ans = (ans + C(n, k)) % mode;
        }
    }
    return ans;
}
bool cp(int n)
{
    int k = (int)sqrt(n);
    return k * k == n;
}
int Try(string &s, int i, int sum, int n)
{
    if (i > n) return cp(sum);
    int ans = 0;
    if (s[i] > '3') ans = (ans + mlem(n - i, sum + 3, n)) % mode;
    if (s[i] > '7') ans = (ans + mlem(n - i, sum + 7, n)) % mode;
    if (s[i] == '3') ans = (ans + Try(s, i + 1, sum + 3, n)) % mode;
    if (s[i] == '7') ans = (ans + Try(s, i + 1, sum + 7, n)) % mode;
    return ans;
}
int g(string s)
{
    int ans = pre[s.size() - 1];
    int n = s.size(); s = " " + s;
    ans = (ans + Try(s, 1, 0, n)) % mode;
    return ans;
}

bool check(string s)
{
    int sum = 0;
    for (char c : s)
    {
        sum += c - '0';
        if (c != '3' && c != '7') return false;
    }
    return cp(sum);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    init();
    int t; cin >> t;
    while (t--)
    {
        string l, r; cin >> l >> r;
        cout << (g(r) - g(l) + check(l) + mode * mode) % mode << '\n';
    }
}

