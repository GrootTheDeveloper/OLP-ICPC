#include <bits/stdc++.h>
using namespace std;
#define int long long
struct dt{
    vector <int> index;
};
string st,s;
unordered_map<char , dt> f;
bool check(char a, char b, int len)
{
    for (int k : f[a].index)
    {
        if (s[k+len-1]==b)
            {
                int l=k,r=k+len-1,t=0,d=1;
                for (int i=0;i<=len/2;i++)
                {
                    if (st[i]!=s[l] || s[r-t]!=st[len-1-t]) {d=0;break;}

                    l++;
                    t++;
                }
                if (d==1) return true;
                //if (j-k==len) return true;
            }
    }
    return false;
}

main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    getline(cin, s);
    for (int i=0;i<s.size();i++) f[s[i]].index.push_back(i);
    int n; cin >> n;
    while (n--)
    {
        cin >> st;
        char a=st[0],b=st[st.size()-1];
        if (check(a,b,st.size())) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
