#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[1111][1111];

void sub1()
{
    int res=0;
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) res=max(res,a[i][j]);
    cout << res;
}
void sub2()
{
    int res=0;
    for (int i=1;i<=n-k+1;i++)
    for (int j=1;j<=n-k+1;j++)
    {
        int t=k,x1=i,y1=j,x2=i,y2=j+k-1,sum=0;
        while (t--)
            sum+=(a[x1++][y1++]+a[x2++][y2--]);
        res=max(res,sum-a[i+k/2][j+k/2]);

    }
    cout << res;
}


main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> k;
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) cin >> a[i][j];
    if (k==1) sub1();
    else sub2();
}
