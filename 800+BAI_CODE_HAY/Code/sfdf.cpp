#include <bits/stdc++.h>
using namespace std;
#define int long long
string s, t;
int k, n, m;

bool check(int x)
{
    vector <int> vec;
    for (int i = 1; i <= m; i++)
    {
        if (s[x] != t[i]) vec.push_back(i);
        x++;
    }
    if (vec.size() != 2) return false;
    return vec[1] - vec[0] == k;
}
int a[202];
int lim;
signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s >> t >> k;
    n = s.size(); m = t.size();
    s = " " + s;
    t = " " + t;
    for (int i = 1; i + m - 1 <= n; i++)
        if (check(i)) a[++lim] = i;
    cout << lim << '\n';
    for (int i = 1; i <= lim; i++) cout << a[i] << ' ';

}
