#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,a,b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        if (a>>1<=b && a<<1>=b && (a+b)%3==0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
