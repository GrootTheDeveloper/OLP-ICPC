#include <bits/stdc++.h>
using namespace std;
#define int long long
int ans,n,k;
int a[22];
bool us[22];

void check()
{
    int ss=1,cnt=0;
    for (int i=1;i<=k;i++)
        if (us[i])
        {
            if (n/ss<a[i]) return;
            ss*=a[i];
            cnt++;
        }
    if (cnt>2)
        ans+=(cnt*(cnt-1)/2+1)-cnt;
}

void Try(int i)
{
    if (i>k) return check(),void();
    us[i]=true;
    Try(i+1);
    us[i]=false;
    Try(i+1);
}


signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> n >> k;
    for (int i=1;i<=k;i++) cin >> a[i],ans+=n/a[i];
    for (int i=1;i<k;i++) for (int j=i+1;j<=k;j++) 
        if (n/a[i]>=a[j]) ans-=n/(a[i]*a[j]);
    Try(1);
    cout << ans << '\n';
    ans=0;
    for (int i=1;i<=n;i++) if (i%2==0 || i%3==0 || i%5==0 || i%7==0) ans++;
    cout << ans;
}