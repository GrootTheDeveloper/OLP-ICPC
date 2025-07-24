#include <bits/stdc++.h>
using namespace std;
#define MAX 3000007
int f[MAX];
bool prime[MAX];

bool check(int n)
{
    int s=0;
    while (n!=0)
    {
        s+=n%10;
        n/=10;
    }
    return s%5==0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    for (int i=2; i*i<=MAX-7; i++)
        if (!prime[i])
            for (int j=i*i; j<=MAX; j+=i) prime[j]=true;

    for (int i=2; i<=MAX-7;i++)
        if (!prime[i]) f[i]=f[i-1]+check(i);
        else f[i]=f[i-1];

    int t; cin >> t;
    while (t--)
    {
        int l,r;
        cin >> l >> r;
        cout << f[r]-f[l-1] << endl;
    }
    return 0;
}

