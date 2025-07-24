#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[111],a[1000006],lim,res,mid,s,n;

unordered_map <int,int> cnt;


void check1()
{
    int sum=0,k=0;
    for (int i=1;i<=lim;i++)
    if (f[i]) sum+=a[i],k+=f[i];
    if (sum==s) res++;
    if (k!=0) cnt[sum]++;
}

void Try1(int i)
{
    if (i>lim) return check1(),void();
    f[i]=1;
    Try1(i+1);
    f[i]=0;
    Try1(i+1);
}
void check2()
{
    int sum=0,k=0;
    for (int i=mid+1;i<=lim;i++)
    if (f[i]) sum+=a[i],k+=f[i];
    if (sum==s) res++;
    if (sum<=s && k) res+=cnt[s-sum];
}
void Try2(int i)
{
    if (i>lim) return check2(),void();
    f[i]=1;
    Try2(i+1);
    f[i]=0;
    Try2(i+1);
}


void sub1()
{
    mid=(n/2);
    lim=mid;
    Try1(1);
    lim=n;
    Try2(mid+1);
    cout << res;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n >> s;
    for (int i=1;i<=n;i++) cin >> a[i];
    if (n<=40) sub1();
}
