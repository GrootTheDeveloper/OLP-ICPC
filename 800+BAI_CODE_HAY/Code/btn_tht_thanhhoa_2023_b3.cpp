#include <bits/stdc++.h>
using namespace std;
#define int long long

char val[40];
unordered_map <char,int> f;

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int k; cin >> k;
    cin.ignore(320000,'\n');
    string s; getline(cin,s);
    for (char i='0';i<='9';i++) f[i]=i-'0',val[i-'0']=i;
    for (char i='A';i<='Z';i++) f[i]=i-'A'+10,val[i-'A'+10]=i;
    for (char i='a';i<='z';i++) f[i]=i-'a'+10;
    for (char c : s)
    if (f.find(c)!=f.end()) cout << val[(f[c]+k)%36];
    else cout << c;
}
