#include <bits/stdc++.h>
using namespace std;
int a[111],f[100005];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,s=0; cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        s+=a[i];
    }
    sort(a+1,a+n+1);
    f[0]=1;
    int res=0;
    for (int i=1;i<=n;i++)
        for (int t=s;t>=a[i];t--)
        if (f[t]==0 && f[t-a[i]]==1) f[t]=1,res+=f[t];
    cout << res << endl;
    for (int i=a[1];i<=s;i++)
        if (f[i]==1) cout << i << ' ';
    return 0;
}
