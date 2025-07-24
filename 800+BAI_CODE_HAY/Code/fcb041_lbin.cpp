#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <int> v;
int n;
bool check()
{
    int res=0,t=-1;
    for (int i=v.size()-1;i>=0;i--)
    {
        t++;
        if (v[i]) res+=pow(2,t);
    }
    return (res<=n);
}
main()
{
    cin >> n;
    string s; cin >> s;
    for (char c : s)
    {
        v.push_back(c-'0');
    }
    int res=0;
    while (!check())
    {
        bool k=false;
        for (int i=1;i<v.size();i++)
        if (v[i]==1)
        {
            v.erase(v.begin()+i);
            res++;
            k=true;
            break;
        }
        if (!k)
        {
            v.pop_back();
            res++;
        }

    }
    cout << res;

}
