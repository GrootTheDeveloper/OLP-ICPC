#include <bits/stdc++.h>
using namespace std;
int f[200005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,ai;
    cin >> n;
    for (int i=1;i<n;i++) cin >> ai, f[ai]=1;
    for (int i=1;i<=n;i++) if (f[i]==0) return cout << i,0;
}

