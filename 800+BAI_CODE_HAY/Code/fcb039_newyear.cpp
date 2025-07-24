#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    int res=0,MAX=a[n];
    for (int i=n;i>0;i--) if (MAX<a[i]) MAX=a[i],res++;
    cout << res;
}
