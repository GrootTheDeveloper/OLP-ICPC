#include <bits/stdc++.h>
using namespace std;
unordered_map <char,int> f;
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    f['A']=4;f['K']=3;f['Q']=2;f['J']=1;
    int res=0;
    while (n--)
    {
        string s; cin >> s;
        for (char c: s) res+=f[c];
    }
    return cout << res,0;

}
