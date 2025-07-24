#include <bits/stdc++.h>
using namespace std;

bool dx(string s,int l, int r)
{
    while (l<r)
    {
        if (s[l]!=s[r]) return 0;
        l++;r--;
    }
    return 1;
}
string check(string s)
{
    int n=s.size();
    if (n<3) return "YES";
    return ((dx(s,0,n-1)||dx(s,1,n-1))? "YES" : "NO" );
}


int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << check(s) << endl;
    }
}
