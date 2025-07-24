#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s1,s2; cin >> s1 >> s2;
    if (s1.size()>s2.size()) return cout << "No",0;
    for (int i=0;i<s1.size();i++)
        if (s1[i]!=s2[i]) return cout << "No",0;
    cout << "Yes";
}
