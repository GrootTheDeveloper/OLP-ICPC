#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t,xf,yf,xg,yg;
    cin >> t;
    while (t--)
    {
        cin >> xf >> yf >> xg >> yg;
        if (xf==xg || yf==yg) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
