#include <bits/stdc++.h>
using namespace std;
#define maxn 10005
int a[maxn],n,d=2,l,r;
int main(){
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        if (a[i]<0 && d==2)
        {
            l=i;
            d-=1;
        }
        else if (a[i]<0 && d==1)
            r=i;
    }
    if (d==2)
        return cout << "-1 -1",0;
    if (d==1 && r==0)
        return cout << l << " " << l,0;
    if (d==1 && r!=0)
        return cout << l << " " << r,0;





}



