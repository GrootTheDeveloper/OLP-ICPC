#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,e;
bool prime[1000006];
int a[100005];
void sie()
{
    prime[1]=true;
    for (int i=2;i<=1000;i++)
        if (!prime[i]) for (int j=i*i;j<=1e6;j+=i) prime[j]=true;
}

void solve()
{
    int res=0;
    for (int i=1;i<=n;i++)
    {
        if (!prime[a[i]])
        {
            int cnt1=0,cnt2=0;
            for (int l=i-e;l>=1;l-=e) 
                if (a[l]==1) cnt1++;
                else break;
            for (int r=i+e;r<=n;r+=e)
                if (a[r]==1) cnt2++;
                else break;
            res+=cnt1+cnt2+cnt1*cnt2;
        }
    }
    cout << res << '\n';
}



signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    sie();
    while (t--)
    {
        cin >> n >> e;
        for (int i=1;i<=n;i++) cin >> a[i];
            solve();
    }
}
