#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    string s;
    cin >> s;
    int d=1,k=1;
    for(int i=1;i<s.size();i++)
        if (s[i]==s[i-1]) d++,k=max(d,k);
        else d=1;
    cout << k;
}
