#include <bits/stdc++.h>
using namespace std;
const int MAX=2e5+5;
int f[MAX];

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,ai; cin >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> ai;
        f[ai]=i;
    }
    int res=0;
    for (int i=1;i<=n;i++) if (f[i]<f[i-1]) res++;
    cout << res+1;
    return 0;
}
