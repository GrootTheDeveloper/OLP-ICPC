#include <bits/stdc++.h>
using namespace std;
int main()
{
    char a,b; cin >> a >> b;
    if a==b: return cout << "D",0;
    if (a=='S' && b=='P' || a=='R' && b=='S' || a=='P' && b=='R')
        cout << "A";
    else
        cout << "B";
    return 0;
}
