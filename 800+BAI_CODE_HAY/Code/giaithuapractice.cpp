#include <bits/stdc++.h>
using namespace std;

long long gt(long long n)
{
    if (n==1 || n==0) return 1;
    return gt(n-1)*n;
}
int main()
{
    long long n;
    cin >> n;
    cout << gt(n);
}
