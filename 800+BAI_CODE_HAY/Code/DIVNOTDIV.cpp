#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    ll t;
    cin >> t;
    while (t--)
    {
        ll a,b,n,m;
        cin >> a >> b >> n;
        if (a%b==0) { cout << -1 << endl; continue;}
        if (n<=a) {cout << a << endl; continue;}
        m=(n/a)*a;
        while (true)
            if (m%a==0 && m%b!=0 && m>=n)
                break;
            else
                m+=a;
        cout << m << endl;

    }
    return 0;

}
