#include <bits/stdc++.h>
using namespace std;

int ConHam(int n)
{
    int res=0;
    while (n>0) res=max(n%10,res),n/=10;return res;
}

int main()
{
    int n,res=0;
    cin >> n;
    while (n!=0) res++,n-=ConHam(n);
    return cout << res,0;
}
