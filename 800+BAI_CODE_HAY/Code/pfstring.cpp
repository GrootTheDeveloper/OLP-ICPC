#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <char,int> f;

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    string s;
    cin >> s;
    int res=0;
    for (char c: s)
    {
        res+=f[c];
        f[c]++;
    }
    cout << res;
}
