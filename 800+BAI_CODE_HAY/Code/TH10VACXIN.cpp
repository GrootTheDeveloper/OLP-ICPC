//https://thptchuyen.ntucoder.net/Problem/Details/11030
#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   freopen ("input.txt", "r", stdin);
   freopen ("output.txt", "w", stdout);
#endif
   int n,m,pa,pb;
   cin >> n >> m;
   cin >> pa >> pb;
   if ((n-m)%(pa+pb)==0)
        cout << (n-m)/(pa+pb);
   else
        cout << (n-m)/(pa+pb)+1;
   return 0;
}
