#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=2e5+5;
int sum[MAX];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n,ai; cin >> n;
    for (int i=1; i<=n; i++) cin >> ai,sum[i]=sum[i-1]+ai;
    int res=1e15;
    for (int i=1;i<=n;i++)res=min(res,abs(sum[n]-2*sum[i]));
    cout << res;

}
