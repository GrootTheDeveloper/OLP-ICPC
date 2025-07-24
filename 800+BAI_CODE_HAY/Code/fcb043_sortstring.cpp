#include <bits/stdc++.h>
using namespace std;
vector<char> vi1;
vector <char> vi2;

bool cmp(char a, char b)
{
    return (int)a>int(b);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s; cin >> s;
    for (char c : s)
    {
        char t=c;
        if (t==tolower(c))
            vi1.push_back(t);
        else
            vi2.push_back(t);
    }
    sort(vi1.begin(),vi1.end(),cmp);
    sort(vi2.begin(),vi2.end(),cmp);
    for (char c: vi2) cout << c;
    for (char c: vi1) cout << c;
    return 0;
}
