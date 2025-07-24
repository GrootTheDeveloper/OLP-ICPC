#include <bits/stdc++.h>
using namespace std;
unordered_map <char,int> f;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cin.tie(0);
    string s1,s2; cin >> s1 >> s2;
    for (char c : s1) f[c]++;
    int res=0;
    for (char c : s2) if (f[c]) res++,f[c]--;
    cout << res;
    return 0;
}
