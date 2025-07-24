/*#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
bool prime[N],ft[N];
int pr[N];

void sie()
{
    ft[1]=true;
    for (int i=2;i<=N;i++)
        if (!prime[i])
        {
            ft[i]=true;
            for (int j=i*i;j<=N;j+=i) prime[j]=true;
        }
        else
            for (int j=i*2;j<=N;j+=i) ft[j]=true;

    for (int i=1;i<=N;i++)
        if (!ft[i]) pr[i]=pr[i-1]+i;
    else
        pr[i]=pr[i-1];
}
main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin >> t;
    sie();
    while (t--)
    {
        int l,r; cin >> l >> r;
        cout << pr[r]-pr[l-1] << '\n';
    }
}*/
//futurenum4
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 3e7; //gioi han

vector<int>prime = {2}; // so nguyen to
vector<int>sum (N + 1); // mang tong don
//vector<int>res; // mang chua so tuong lai - khong can thiet vi da optimize (toi uu) code

int n;

int L, R;

void sieve() { //sang + danh dau
	vector <bool> isPrime(N / 2 + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 3; i <= N / 2; i += 2) {
         if(isPrime[i] == true) {
         	 prime.push_back(i);
             for(int j = i * i; j <= N / 2; j += i * 2)
                 isPrime[j] = false;
        }
    }
}

void process() // su dung ham process so tuong lai 3
{
	sum.assign(N,0);
	int y = 0;
	for (int i = 0; prime[i] * prime[i] <= N; i++)
	{
		for (int j = i; j < prime.size() && prime[i] * prime[j] <= N; j++)
		{
		//	dat prime[i]*prime[j] o vi tri prime[i]*prime[j], toi uu thoi gian & bo nho
			sum[prime[i] * prime[j]] = prime[i] * prime[j];
		}
	}
	//khong can sort
	sum.push_back(0);
	for (int i = 1; i < N; i++)
	{
		sum[i] += sum[i - 1];
	}
}

signed main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  sieve(); //sang
  process(); //xu ly
  cin >> n; //so truy van
  while (n--)
  {
  	int l,r;
  	cin >> l >> r;
  	cout << sum[r] - sum[l - 1] << '\n'; //tra loi cho tung truy van
  }
  return 0;
}
