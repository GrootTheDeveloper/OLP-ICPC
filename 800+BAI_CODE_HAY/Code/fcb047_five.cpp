#include <bits/stdc++.h>
using namespace std;
int a[6];
int main()
{
    for (int i=1;i<=5;i++) cin >> a[i];
    int res=0;
    for (int i=5;i>=1;i--) if (a[i])res=res*10+i;
    return cout << res,0;
}
