#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MODE=1e9+7;
int sub(int x)
{
    return (x%MODE*((x+1)%MODE)/2)%MODE;
}
main()
{
    int n; cin >> n;
    int res=0;
    for (int l=1;l<=n;l++)
    {
        int r=n/(n/l);
        int sum=(n/l)%MODE*(sub(r)-sub(l-1)+MODE)%MODE;
        res=(res+sum)%MODE;
        l=r;
    }
    cout << res;
}
