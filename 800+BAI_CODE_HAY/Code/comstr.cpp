#include <bits/stdc++.h>
using namespace std;
string s;
int d=1;
void put(int i)
{
    if (d!=1) cout << d;
    cout << s[i];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    for (int i=0;i<s.size();i++)
    {
        if (i==s.size()-1)
        {
            put(i);
            break;
        }
        if (s[i]==s[i+1]) d++;
        else {put(i);d=1;}
    }
}
