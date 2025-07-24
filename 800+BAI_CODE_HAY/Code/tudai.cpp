#include <bits/stdc++.h>
using namespace std;
#define int long long

main()
{
    //freopen("t.inp","r",stdin);
    string s; getline(cin,s);
    string res;
    while (s.size())
    {
        while (s.back()==' ') s.pop_back();
        string st="";
        while (s.size())
        {
            if (s.back()!=' ') st.push_back(s.back()),s.pop_back();
            else break;
        }
        if (st.size()>res.size()) res=st;

    }
    cout << res.size() << endl;
    while (res.size()) cout << res.back(),res.pop_back();
}
