#include <bits/stdc++.h>
using namespace std;
int main()
{ int q,n;
cin >> q ;
for (int i=1; i<=q; i++)
{   cin >>n;
    if ((n%4==0) && (n%100 !=0) || (n%400==0))  
        cout << "YES" << endl;
    else
        cout <<"NO"<< endl;
}
}
