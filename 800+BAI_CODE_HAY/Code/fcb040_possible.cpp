#include <bits/stdc++.h>
using namespace std;
#define int long long
int sum(int n) {return n*(n+1)/2;}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int n,s;
        cin >> n >> s;
        s=abs(s);
        cout << ((sum(n)>=s && (sum(n)%2+s%2!=1))? "YES" : "NO");
        cout << endl;
    }

}
