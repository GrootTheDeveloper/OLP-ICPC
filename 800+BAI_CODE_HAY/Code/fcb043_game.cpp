#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    string s;
    cin >> s;
    int cnt=0;
    for (int i=0;i<=s.size()-11;i++)
    {
        if (s[i]=='8')  cnt++;
    }
    if (cnt>(n-11)/2) cout << "YES";
    else cout << "NO";
}
