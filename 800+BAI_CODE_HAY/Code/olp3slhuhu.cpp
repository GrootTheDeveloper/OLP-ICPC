#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
bool cp(int n)
{
    int lim=trunc(sqrt(n));
    return (lim*lim==n);
}
void sub1()
{
    cout << (int)sqrt(n)-1;
}
void sub2()
{
    int res=0;
    for (int i=2;i<=n-1;i++)
        for (int j=i+1;j<=n;j++) res+=cp(i*j);
    cout << res;
}
void sub3()
{
    int res=0;
    for (int i=2;i<=n-2;i++)
    for (int j=i+1;j<=n-1;j++)
    for (int z=j+1;z<=n;z++) res+=cp(i*j*z);
    cout << res;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    if (k==1) sub1();
    else if (k==2 && n<=5000) sub2();
    else if (k==3 && n<=500) sub3();


}
