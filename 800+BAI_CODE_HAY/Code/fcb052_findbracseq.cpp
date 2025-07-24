    #include <bits/stdc++.h>
    using namespace std;

    int main()
    {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        string s; cin >> s;
        int open=0,ans=0;
        for (char c : s)
        {
            if (c=='(') open++;
            else if (c==')' && open>0) open--,ans+=2;
        }
        return cout << ans,0;
    }
