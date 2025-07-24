#include <bits/stdc++.h>
using namespace std;
#define int long long

int ai,n,lim,p[10000];
bool prime[10004];
void sie()
{
    for (int i=2;i<=100;i++)
        if(!prime[i]) for (int j=i*i;j<=1e4;j+=i) prime[j]=true;
    for (int i=2;i<=1e4;i++) 
        if (!prime[i]) lim++,p[lim]=i;
}
int f(int n)
{
    int res=1;
    int t=0;
    for (int i=1;i<=lim;i++)
    {
        if (p[i]>n) break;
        while (n%p[i]==0) t++,n/=p[i];
        res*=(t+1);
        t=0;
    }
    if (n!=1) res*=2;
    return res; 
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    sie();
    int n; cin >> n;
    int res=0;
    for (int i=1;i<=n;i++)
    {
        cin >> ai;
        res+=ai*f(ai);
    }
    cout << res;
}
