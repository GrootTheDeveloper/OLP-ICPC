#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    string s; cin >> s;
    string h,p;
    int i=0;
    while (s[i]!=':') h+=s[i],i++;
    i++;
    while (i!=s.size()) p+=s[i],i++;
    int x=stoi(h),y=stoi(p);
    if (n==12)
    {
        if (x>12) cout << 0 << x%10 << ':';
        else cout << h << ':';
        if (y>59) cout << 0 << y%10;
        else cout << p;
    }
    else
    {
        if (x>23) cout << 0 << x%10 << ':';
        else cout << h << ':';
        if (y>59) cout << 0 << y%10;
        else cout << p;
    }
    return 0;

}
