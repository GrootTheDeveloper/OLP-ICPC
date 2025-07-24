#include <bits/stdc++.h>
using namespace std;
#define int long long

 main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(NULL);
    int n;cin>>n;
    while (n>1)
    {
        cout << n << ' ';
        if (n%2==0)
            n/=2;
        else
            n=n*3+1;
    }
    cout << n;
}

