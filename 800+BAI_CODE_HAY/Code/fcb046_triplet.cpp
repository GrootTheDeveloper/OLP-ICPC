#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k; cin >> n >> k;
    int res=0;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
            if (k-(i+j)<=n && k-(i+j)>=0) res++;
    return cout << res,0;
}
