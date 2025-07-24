#include <bits/stdc++.h>
using namespace std;
#define int long long
int sum(int n) {int res=0; while (n!=0) res+=n%10,n/=10; return res;}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=2;
    while (t--)
    {
        int n,k; cin >> n >> k;
        int res=0,temp=k;
        while (temp<=n) res+=sum(temp),temp+=k;
        cout << res << endl;
    }
}
