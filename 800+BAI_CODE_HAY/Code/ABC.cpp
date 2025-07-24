#include <bits/stdc++.h>
using namespace std;
int solve(int n)
{
   if (n==0) return 0;
   if (n==1) return 0;
   if (n==2) return 1;
   int k=1,ans=0;
   while (k<n)
   {
        if (n%k==0)
            ans+=n/k-1;
        else
            ans+=n/k;
        k+=1;
   }
   return ans;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    cout << solve(n);
    return 0;

}
