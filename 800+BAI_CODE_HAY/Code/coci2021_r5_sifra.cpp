#include <bits/stdc++.h>
using namespace std;
unordered_map <string,int> f;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s; cin >> s; s=s+' ';
    string st;
    int res=0;
    for (int i=0;i<s.size();i++)
    {
        if (isdigit(s[i]))
        {
            st+=s[i];
            if (!isdigit(s[i+1])) res+=(!f[st]),f[st]=1,st="";
        }
    }
    cout << res;


}
