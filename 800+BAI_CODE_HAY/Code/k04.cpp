// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int main() {
   double b,s;
   cin >> b >>s;
   if ((int)((s*2)/b)==(s*2)/b)
      cout << (int)((s*2)/b);
   else 
      cout << (int)(((s*2)/b)+1);
   return 0;
}
