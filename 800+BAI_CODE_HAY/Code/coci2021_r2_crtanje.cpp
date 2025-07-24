#include <bits/stdc++.h>
using namespace std;
char a[1000][1000];
unordered_map <char,char> f;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    f['+']='/';f['-']='\';

    int n; cin >> n;
    string s; cin >> s;
    int MAX=0,sum=0;
    for (char c : s)
    {
        if (c=='-') sum--;
        else if (c=='+') sum++;
        MAX=max(sum,MAX);
    }
    int x,y;
    if (MAX>0) x=MAX,y=1;
    else x=1,y=1;
    if ()
    for (int i=1;i<s.size();i++)
    {

    }
}
