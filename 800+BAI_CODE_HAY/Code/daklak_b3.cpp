#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int f[256];
void solve()
{
    memset(f,0,sizeof(f));
    cin >> s;
    for (char c : s) f[c-'a']++;
    for (int i=0;i<s.size();i++)
    if (f[s[i]-'a']==1) return cout << i+1 << '\n',void();
    cout << -1 << '\n';

}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while(t--)
    {
        solve();
    }
}
