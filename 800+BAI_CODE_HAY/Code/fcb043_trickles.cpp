#include <bits/stdc++.h>
using namespace std;
#define int long long
int cnt[2222];
vector <int> vi;
const int mode=1e9+7;

int power(int a, int b)
{
    int res=1;
    while (b>0)
    {
        if (b&1) res=res*a%mode;
        a=(a*a)%mode;
        b >>=1;
    }
    return res;
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n; cin >> n;
    for (int i=1;i<=n;i++)
    {
        int ai;
        cin >> ai;
        if (!cnt[ai]) vi.push_back(ai);
        cnt[ai]++;
    }
    sort(vi.begin(),vi.end());
    int l=0,dem=0,res=1;
    while (l<=vi.size()-3)
    {
        int r=l+1;
        while (r<=vi.size()-2)
        {
            int k=r+1;
            while(k<=vi.size()-1 && vi[k]<vi[l]+vi[r])
            {
                int temp=3*vi[l]+3*vi[r]+5*vi[k];
                if (temp%3==0 || temp%5==0 || temp%8==0)
                {
                    int x=vi[l]+vi[r]-vi[k];
                    int y=cnt[vi[l]]*cnt[vi[r]]*cnt[vi[k]];
                    res=res*power(x,y)%mode;
                    dem++;
                }
                k++;
            }
            r++;
        }
        l++;


    }
    if (dem) cout << res;
    else cout << 0;

}
