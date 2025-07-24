#include <bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    freopen ("addsubtract.inp","r",stdin);
    freopen ("addsubtract.out","w",stdout);
    string s; cin >> s;
    string st="";
    int res=0,k=1;
    for (char c : s)
    {
        if (c=='-' || c=='+')
        {
            if (st.size()) res+=stoll(st)*k;
            st=""+c;
            k=((c=='-')?-1:1);
        }
        else st+=c;
    }
    res+=stoll(st)*k;
    cout << res;

}
