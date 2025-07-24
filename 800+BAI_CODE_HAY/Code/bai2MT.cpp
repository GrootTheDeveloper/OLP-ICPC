#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[30],n,k;

void xuat()
{
    for (int i=1;i<=n;i++) cout << a[i]; 
    cout << '\n';
}

void Try(int i)
{
    if (i==n+1) {xuat();return;}
    for (int j=0;j<=k-1;j++)
    {
        a[i]=j; 
        Try(i+1);
    }
    
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("nhiphan.inp","r",stdin);
    //freopen("nhiphan.out","w",stdout);
    
    cin >> n >> k;
    Try(1);
}


