#include <bits/stdc++.h>
using namespace std;
long long gcd(int a, int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    long long m=0,ai; cin >> ai;
    for (int i=1;i<n;i++)
    {
        int k;
        cin >> k;
        m=gcd(m,abs(k-ai));
    }
    return cout << m,0;

}
