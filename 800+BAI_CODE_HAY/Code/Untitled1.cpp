#include <bits/stdc++.h>
using namespace std;
#define int long long
unordered_map <int,int> cnt;
int a[10004];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n; cin >> n;
    int sum=0;
    for (int i=1;i<=n;i++) cin >> a[i],sum+=a[i],cnt[a[i]]++;
    sort(a+1,a+n+1);
    cout << a[n] << '\n';
    cout << a[1] << '\n';
    double avg=(double)sum/n;
    cout << setprecision(12) << fixed << avg << '\n';
    cout << a[n/2+1] << '\n';
    int res=-1e9;
    for (int i=1;i<=n;i++)
    {
        if (cnt[a[i]]>cnt[res]) res=a[i];
    }
    cout << res << '\n';
    double ans=0;
    for (int i=1;i<=n;i++) ans+=(a[i]-avg)*(a[i]-avg);
    cout << setprecision(12) << fixed << sqrt(ans/n);


}
