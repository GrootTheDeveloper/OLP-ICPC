#include <bits/stdc++.h>
using namespace std;
int tong(long long n)
{
    int s=0;
    while (n>0)
    {
        s+=n%10;
        n/=10;
    }
    return s;
}
int main()
{
    long long n;
    cin >> n;
    while (n>9) n=tong(n);
    cout << n;
}
