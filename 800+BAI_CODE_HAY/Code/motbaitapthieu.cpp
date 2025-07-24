#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n+1],k=0;
    for (int i=2;i<=n;i+=2){
        a[i]=1 + a[i/2];
        k+=a[i];
    }
    cout << k;
    return 0;
}
