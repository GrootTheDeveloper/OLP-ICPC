//https://lqdoj.edu.vn/problem/thtkvmta3
#include <bits/stdc++.h>
using namespace std;
long long l,r,n,s;
int main()
{
    cin >> n >> l >> r;
    s=r*(r+1)/2 - l*(l-1)/2;
    if (l%2==0)
        s-=1;
    if (r%2!=0)
        s+=1;
    cout << s;
}
