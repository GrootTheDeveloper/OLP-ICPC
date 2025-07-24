#include <bits/stdc++.h>
using namespace std;
#define int long long

string fn(string s)
{
    if (s.size()==1) return s;
    int temp=0;
    for (char c: s) temp+=c-'0';
    return fn(to_string(temp));
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s; cin >> s;
    cout << fn(s);
}
