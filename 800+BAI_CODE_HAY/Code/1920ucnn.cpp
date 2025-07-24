#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    int n,d,ai; cin >> n >> d;
    while (n-->1)
    {
        cin >> ai;
        d=gcd(d,ai);
    }
    if (d==1) return cout << -1,0;
    if (d%2==0) return cout << 2,0;
    for (int i=3;i<=d;i+=2)
        if (d%i==0) return cout << i,0;

}
