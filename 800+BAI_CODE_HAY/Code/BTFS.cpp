#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k,t=4096;
    cin >> n;
    if (n%t==0)
        cout << n/t*4;
    else
        cout << (n/t+1)*4;
    return 0;

}
