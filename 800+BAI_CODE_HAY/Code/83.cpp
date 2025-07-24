#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> f[30];
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s1, s2; cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++)
        f[s1[i] - 'a'].push_back(i + 1);
    int n = s2.size(), m = s1.size();
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = s2[i - 1] - 'a';
        auto pos1 = lower_bound(f[x].begin(),end(f[x]), i);
        auto pos2 = upper_bound(f[x].begin(),end(f[x]), m - n + i);
        if (pos2 - pos1 > 0) res += pos2 - pos1;
    }
    cout << res;
}
