#include <bits/stdc++.h>
using namespace std;

main()
{
    string s;
    getline(cin,s);
    for (char c: s)
    {
        if ((c>='a' && c<='z') || (c>='A' && c<='Z')) cout << c;
    }
}
