//https://thptchuyen.ntucoder.net/Problem/Details/11026
#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    long long  n,d=0;
    int k=1;
    cin >> n;
    if (n==0){
        cout << 0;
        return 0;
    }
    while (pow(5,k)<=n){
        d=d+n/pow(5,k);
        k=k+1;
    }
    cout << d;

    return 0;
}
