#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
int a[3333];
signed main()
{
    int x,y,z,n; cin >> x >> y >> z >> n;
    int k=0;
    for (int i=x;i<x+n;i++) a[++k]=i;
    for (int i=y;i<y+n;i++) a[++k]=i;
    for (int i=z;i<z+n;i++) a[++k]=i;
    sort(a+1,a+k+1);
    int res=0;
    for (int i=1;i<k;i++) for (int j=i+1;j<=k;j++)
        res+=lower_bound(a+j+1,a+k+1,a[i]+a[j])-a-1-j;
    cout << res;
}
