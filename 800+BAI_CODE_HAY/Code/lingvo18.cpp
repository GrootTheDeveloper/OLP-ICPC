#include <bits/stdc++.h>
using namespace std;
#define int long long
string a[10];
string ss(string s1, string s2)
{
    if (s1>s2) return s1;
    else return s2;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for (int i=0;i<=9;i++)
    {
        string s;cin >> s;
        a[i]=s;
    }
    int t; cin >> t;
    while (t--)
    {
        int  n; cin >> n;
        string res=a[n%10]; n/=10;
        while (n!=0) res=ss(res,a[n%10]),n/=10;
        cout << res << '\n';
    }

}
