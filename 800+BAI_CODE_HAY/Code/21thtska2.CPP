#include <bits/stdc++.h>
using namespace std;
#define int long long 

main()
{
    int n;cin >> n;
    int res=0;
    for (int i=1;i<=9;i++)
    {
        int k=i;
        while (k<=n)
        {
            res++;
            k=k*10+i;
        }
    }
    cout << res;
}
