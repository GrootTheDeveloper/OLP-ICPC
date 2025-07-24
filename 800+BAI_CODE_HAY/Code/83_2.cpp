#include <bits/stdc++.h>
using namespace std;
#define int long long

int pre[30][100005];
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s1,s2; cin >> s1 >> s2;
    int m = s1.size(), n = s2.size();
    s1 = "#" + s1;
    s2 = "#" + s2;
    for (int i = 1; i <= m; i++)
        for (char c = 'a'; c <= 'z'; c++)
            pre[c - 'a'][i] = ((c == s1[i])? pre[c - 'a'][i - 1] + 1 : pre[c - 'a'][i - 1]);
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += pre[s2[i] - 'a'][m - n + i] - pre[s2[i] - 'a'][i - 1];
    cout << res;
}
