#include<bits/stdc++.h>
using namespace std;

pair<int, int> a[100005];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  int n;
  cin >> n;

  for(int i = 1; i <= n; i++){
    cin >> a[i].first >> a[i].second;
    a[i].first -= a[i].second;
    a[i].second = a[i].first + 2 * a[i].second;
    swap(a[i].first, a[i].second);
  }

  sort(a + 1, a + 1 + n);

  int res = 0 ;

  for(int last = -1e9, i = 1; i <= n; i++)
    if(a[i].second >= last)
      last = a[i].first,
      res++;

  cout << res;

  return 0;
}
