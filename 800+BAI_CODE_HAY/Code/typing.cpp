#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9 + 7;

int AnhIuEm (string &s)
{
    int n = s.size();
    s = " " + s + "A";
    int fir = 1;
    while (s[fir] == 'T') fir++;
    char last = s[fir];
    int res = 0;
    for (int i = fir; i <= n; i++)
        if (s[i] != 'T' && s[i] != last) 
        {
            res ++;
            last = s[i];
        }
    return res;
}

int pre[1000005], sum[1000005], nxt[100005];
void DeoIuem(string &s)
{
    memset(nxt, 0, sizeof(nxt));
    int n = s.size();
    s = " " + s;
    int fir = 1;
    while (s[fir] == 'T') fir++;
    char last = s[fir];
    for (int i = 2; i <= n; i++)
    {
        if (s[i] != last && s[i] != 'T')
        {
            pre[i] = pre[i - 1] + 1;
            last = s[i];
        } else pre[i] = pre[i - 1];
        if (s[i] != 'T' && s[i - 1] == 'T')
        {
            int l = i - 1;
            while (s[l] == 'T') nxt[l--] = i;
        }
    }
    sum[n + 1] = 0;
    for (int i = n; i >= 1; i--) sum[i] = (sum[i + 1] + pre[i]) % mode;
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] != 'T') res = (res + sum[i + 1] - pre[i] * (n - i) % mode) % mode;
        else if (nxt[i]) res = (res + sum[nxt[i] + 1] - pre[nxt[i]] * (n - nxt[i]) % mode) % mode;
    }
    cout << res << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q; cin >> q;
    while (q--)
    {
        int kind; string s;
        cin >> kind >> s;
        if (kind == 0) cout << AnhIuEm(s) << '\n';
        else DeoIuem(s);
    }
}
