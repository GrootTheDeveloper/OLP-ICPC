#include <bits/stdc++.h>
using namespace std;

int main()
 {
    int a,n,k,b; cin >> a >> n >> k >> b;
    int x=a-1,val=a*b;
    int res=0;
    while (n>0)
    {
        if (k>=x) k-=x,res++,n-=val;
        else if (k)
        {
            res++;
            n-=(k+1)*b;
            k=0;
        }
        else if(k==0)
        {
            n-=b;
            res++;
        }
    }
    cout << res;
 }
