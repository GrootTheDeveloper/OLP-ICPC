#include <bits/stdc++.h>
using namespace std;
#define int long long
int hang[1111],cot[1111];
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n; cin >> n;
    int ai;
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) cin >> ai,hang[i]+=ai,cot[j]+=ai;
    int res=0;
    for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) res+=(hang[i]==cot[j]);
    cout << res;

}
