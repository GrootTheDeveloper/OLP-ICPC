#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int k; cin >> k;
    string s; cin >> s;
    int N=s.size()-k+1;
    int beg=0,index;
    while (k--)
    {
        int sol=10;
        for (int i=beg; i<N; i++)
            if (sol>s[i]-'0')
            {
                index=i;
                sol=s[i]-'0';
            }
        cout << sol;
        beg=index+1;
        N+=1;
    }

    return 0;

}
