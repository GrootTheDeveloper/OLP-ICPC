#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int check1(int n)
{
    if (n==1) return 1;
    return 0;
}
int check2(int n)
{
    if (n==0) return 1;
    return 0;
}
int solve(int i, int j)
{
    return n-j+1;
}

main()
{
    freopen ("DRX02T1.inp","r",stdin);
    freopen ("DRX02T1.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    map<char, int > f;
    char a[1000005];
    string s;
    int k; cin >> n >> k;
    cin >> s;
    int i=0;
    for (char c : s)
    {
        i+=1;
        a[i]=c;
    }
    int j=0,res=0,d=0;
    i=1;
    while (j<n)
    {
        j++;
        f[a[j]]++;
        d+=check1(f[a[j]]);
        while (d==k)
        {

            res+=solve(i,j);
            f[a[i]]--;
            d-=check2(f[a[i]]);
            i++;
        }
    }
    cout << res << endl;


}



