#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s; getline(cin,s);
    s.push_back(' ');
    int res=0;
    for (int i=1;i<s.size();i++) if (s[i]==' ' && s[i-1]!=' ') res++;
    cout << res;
}
