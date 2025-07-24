#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    int l,r,res=0;
    cin >> l >> r;
    for (int i=1;i<=r;i++)
    {
        for (int j=i*2;j<=r;j+=i) a[j]+=i;
        if (i>=l && a[i]>i) res++;
    }
    cout << res;
    return 0;
}

