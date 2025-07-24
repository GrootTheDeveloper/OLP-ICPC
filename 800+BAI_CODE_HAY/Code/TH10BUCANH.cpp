#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   freopen ("input.txt", "r", stdin);
   freopen ("output.txt", "w", stdout);
#endif
   int w,n;
   cin >> w >>n;
   int a[n];
   for (int i=0;i<n;i++)
        cin >> a[i];
   sort(a,a+n);
   int d=0;
   for (int i=0;i<n;i++)
   {
       if (a[i]<w)
       {
           d+=1;
           w-=a[i];
       }
       else
            break;
   }
   cout << d;
   return 0;
}
