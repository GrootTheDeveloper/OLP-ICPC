#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    while (t--)
    {
        int n,res=0; cin >> n;
        for (int i=1;i<=n;i*=10)
        {
            if (n<i*10) res+=n/i;
            else res+=9;
        }
        cout << res << endl;
    }
    return 0;
}
