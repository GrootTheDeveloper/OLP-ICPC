#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,res;
main()
{
    cin >> n;
    int N=trunc(sqrt(n));
    for (int i=1;i<=N;i++)
    {
        if (n%i==0) res+=2;
    }
    if (N*N==n) res--;
    cout << res;
}
