#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,mid,x,a[50],res;
bool choose[50];
unordered_map <int,int> f;

void check(int lim)
{
    int s=0;
    for (int i=1;i<=n;i++) s+=(choose[i]*a[i]);
    if (lim==mid) 
    {
        f[s]++;
        if (mid==n) res+=(x==s);
    }
    else res+=f[x-s];
    
}
void Try(int i, int lim)
{
    if (i>lim) return check(lim);
    choose[i]=1;Try(i+1,lim);
    choose[i]=0;Try(i+1,lim);
}


main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> x;
    for (int i=1;i<=n;i++) cin >> a[i];
    mid=(1+n)/2;
    Try(1,mid);
    memset(choose,0,sizeof(choose));
    Try(mid+1,n);
    cout << res;

}
