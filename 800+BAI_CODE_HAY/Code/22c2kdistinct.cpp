#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
map <int , int> f;

int check1(int n)
{
    if (n==1) return 1;
    return 0;
}
int check2(int n)
{
    if (n==0) return 1;
    return 0;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int sub;cin >> sub;
    int n,k; cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    int i=1,j=0,d=0,res=0;
    while (j<n)
    {
        j++;
        f[a[j]]++;
        d+=check1(f[a[j]]);
        while (d>k)
        {
            f[a[i]]--;
            d-=check2(f[a[i]]);
            i++;
        }
        res+=j-i+1;

    }
    cout << res,0;
}


