#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check(int n)
{
    int res=0;
    for (int i=1;i<=sqrt(n);i++)
        if (n%i==0)
        res=res+1+(i!=n/i);
    return res==4;

}
main()
{
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    int res=0;
    for (int i=1;i<=sqrt(n);i++)
        if (n%i==0) res+=check(i)+((i!=n/i)? check(n/i):0);
    cout << res;

}
