#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int x,n; cin >> x >> n;
    int res=(n+1)*x;
    int sum=0;
    for (int i=1;i<=n;i++)
    {
        int k; cin  >> k; sum+=k;
    }
    return cout << res-sum,0;
}
