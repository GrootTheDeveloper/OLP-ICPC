#include <bits/stdc++.h>
using namespace std;
#define in cin>>
#define out cout <<
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s; in s;
    string st="";
    for (char c : s)
        if (c==' ') break;
        else st+=c;
    if (st=="I") return out "am",0;
    else if (st=="He" || st=="She" || st=="It") return out "is",0;
    else if (st=="We" || st=="They" || st=="You") return out "are",0;
    return out "is",0;



}
