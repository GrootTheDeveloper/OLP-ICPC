#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode = 1e9+7;
main()
{
    int n; cin >> n;
    if (n%2!=0) return cout << 0,0;
    int x1=1,x2=1;
    for (int i=n/2+2; i<=n; i++)
        x1=(x1*i)%mode;
    for (int i=1;i<=n/2;i++)
        x2=(x2*i)%mode;
    cout << (x1%mode/x2%mode) %mode;
}
