#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9, base = 311;
int T[200005], p[100005];

int get(int l, int r)
{
    return (T[r] - T[l - 1] * p[r - l + 1] + mode * mode) % mode;
}
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int len = s.size();
    s = " " + s;
    p[0] = 1;
    for (int i = 1; i <= len; i++)
    {
        p[i] = p[i - 1] * base % mode;
        T[i] = (T[i - 1] * base + s[i] - 'a' + 1) % mode;
    }
    int res = 0;
    for (int i = 1; i <= len; i++)
    {
        int Hash = get(1, i);
        int pos = i;
        while (get(pos + 1, pos + i) == Hash) pos += i;
        if (len - pos  > i) continue;
        if (pos == len) { res = i; break;}
        if (get(pos + 1, len) == get(1, len - pos)) {res = i; break;}
    }
    for (int i = 1; i <= res; i++) cout << s[i];
}
