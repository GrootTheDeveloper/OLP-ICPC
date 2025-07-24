#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    string s;
    getline(cin,s);
    int ans=0,open=0;
    for (char i : s)
    {
        if (i=='(') open++;
        else if (i==')' && open!=0)
        {
            ans+=2;
            open--;
        }
    }
    cout << ans;

    return 0;
}
