#include <bits/stdc++.h>
using namespace std;
#define int long long 
int l,r,n,k,res;
int a[500005];
int v[1000];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    int res=0,k=0;
    for (int i=1;i<=n;i++)
    {
        l=i;r=i;
        while (a[l-1]%a[i]==0 && l-1!=0) l--;
        while (a[r+1]%a[i]==0 && r+1<=n) r++;
        if (r-l>res)
        {
            
            k=1;
            v[k]=l;
            res=r-l;
        }
        else if (r-l==res && l!=v[k]) k++,v[k]=l;
    }
    cout << k << ' ' << res << '\n';
    for (int i=1;i<=k;i++) cout << v[i] << ' ';
}
