#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=1e5+5;
int f[MAX],a[MAX];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin >> t;
    a[0]=0;f[0]=0;
    a[1]=1;f[1]=1;
    int temp=1;
    for (int i=2;i<=MAX;i++)
    {
        if (i%2==0) a[i]=a[i/2],temp=max(temp,a[i]),f[i]=temp;
        else a[i]=a[i/2]+a[i/2+1],temp=max(temp,a[i]),f[i]=temp;
    }
    while (t--)
    {
        int n;
        cin >> n;
        cout << f[n] << endl;
    }
    return 0;

}
