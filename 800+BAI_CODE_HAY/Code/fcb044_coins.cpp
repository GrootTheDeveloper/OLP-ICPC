#include <bits/stdc++.h>
using namespace std;
#define int long long
main()
{
    int m,k,a,b; cin >> m >> k >> a >> b;
    int x=min(a,b),y=max(a,b);
    int temp=(y-x)/k;
    temp=min(temp,m);
    x+=temp*k;
    m-=temp;
    if (m>0)
    {
        x+=(m/2+(m%2==1))*k;
        y+=(m/2)*k;
    }
    cout << abs(x-y);



}
