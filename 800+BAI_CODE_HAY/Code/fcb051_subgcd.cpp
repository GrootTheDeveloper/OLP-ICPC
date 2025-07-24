#include <bits/stdc++.h>
using namespace std;
const int MX = 1e6 + 5;
bool f[MX];
int gcd(int a, int b) { if (b==0) return a; return gcd(b,a%b);}

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    int ai;
    for (int i=1;i<=n;i++) cin >> ai,f[ai]=true;
    int res=0;
    for (int i=1;i<MX;i++)
    {
        int d=0;
        for (int j=i;j<MX;j+=i)
            if (f[j]) d=gcd(d,j);
        if (d==i) res++;
    }
    return cout << res,0;

}
