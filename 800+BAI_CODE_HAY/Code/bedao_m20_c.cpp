#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1001],f[11];
const int oo=1e10;

bool check(int n)
{
    set<int> s;
    int d=0;
    while (n!=0)
    {
        if (f[n%10]) break;
        s.insert(n%10);
        d++;
        n/=10;
    }
    if (n>0 || s.size()!=d) return 0;
    return 1;


}
void push(int n) {while (n!=0) f[n%10]=1,n/=10;}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
   while (t--)
    {
        int n; cin >> n;
        for (int i=1;i<=n;i++) cin >> a[i];
        sort(a+1,a+n+1);
        int res=0;
        for (int i=n;i>0;i--)
        {
            if (a[i]<oo && check(a[i])) res+=a[i],push(a[i]);
        }
        cout << res << endl;

    }
}
