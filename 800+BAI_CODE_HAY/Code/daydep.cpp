#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int ai,s=0;
    for (int i=1;i<=n;i++) cin >> ai,s+=ai;
    if (s!=n-1) return cout << "NO",0;
    else return cout << "YES",0;
}
