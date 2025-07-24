#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long res=0;
    int n;
    cin >> n;
    for (int i=1;i<n;++i) res+=max(0,n-max(i,n-i+1));
    /*{
        int  temp=max(i,n-i+1);
        int  l=max(0,n-temp);
        res+=l;
    }*/
    return cout << res,0;

}
