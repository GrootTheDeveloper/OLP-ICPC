#include <bits/stdc++.h>
using namespace std;
#define int long long
string s,st,res;
int k,n,a[1000005];
deque<int> q;
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("BIGNUM.inp","r",stdin);
    freopen("BIGNUM.out","w",stdout);
    cin >> s;
    cin >> k;
    for (char c : s)
    if ('0'<=c && c<='9') n++,a[n]=c-'0';
    int h=1,t;
    while (k)
    {
        int m=a[h];
        for (int i=h;i<=n-k+1;i++) if (m<a[i]) m=a[i],h=i;
        cout << m;
        h++;
        k--;

    }





}
