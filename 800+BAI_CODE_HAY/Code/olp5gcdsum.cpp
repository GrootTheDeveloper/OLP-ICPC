#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mode=998244353;

main()
{
    int a,b; cin >> a >> b;
    if (a<b) swap(a,b);
    int res=0;
    while (b!=0)
    {
        int n=a/b;
        int u1=a-(n-1)*b;
        bool ktmode=false;
        int m=n,k=2*u1+(n-1)*b;
        if (m%2==0) m/=2,ktmode=true;
        if (ktmode==false) k/=2;
        res=(res+(m%mode)*(k%mode))%mode;
        a%=b;
        swap(a,b);
    }
    cout << res;

}
