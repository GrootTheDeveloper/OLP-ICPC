#include <bits/stdc++.h>
using namespace std;
string s;
string solve()
{
    for (int i=0;i<s.size()-1;i++)
        if (s[i]==s[i+1]) return "YES\n";
    return "NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--) cin >> s, cout << solve();
    return 0;
}
