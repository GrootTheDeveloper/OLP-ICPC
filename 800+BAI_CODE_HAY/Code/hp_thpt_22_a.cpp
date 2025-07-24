#include <bits/stdc++.h>
using namespace std;

main()
{
    string s; cin >> s;
    int res=0;
    for (int i=0;i<=s.size()-5;i++)
    if (s[i]=='v' && s[i+1]=='i' && s[i+2]=='r' && s[i+3]=='u' && s[i+4]=='s') res++;
    cout << res;
}
