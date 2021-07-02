int fastExpo(int a, int n, int mod) {
  int result = 1;
  while ( n > 0) {
    if ( n & 1 )
      result = (result * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return result;
}

int modInverse(int n, int mod) {
  return fastExpo(n, mod - 2, mod);
}
vector<int> factorial(int n) {
  std::vector<int> fac(n + 2, 0);
  fac[0] = 1;
  for (int i = 1; i <= n; i++)
    fac[i] = (fac[i - 1] * i) % M;

  return fac;
}

int __nCr(int n, int r, vector<int>& Fact, int mod) {
  int ans = (((Fact[n] * modInverse(Fact[r], mod)) % mod)
             * modInverse(Fact[n - r], mod)) % mod;
  return ans;
}

// Ulta dfs
set<int>g[N];
set<int>vis;
vector<int>ans;
int n, m;
int dfs(int u) {
  int sz = 1;
  for (auto it = vis.begin(); it != vis.end();) {
    //int x=*it;
    if (!g[u].count(*it)) {
      vis.erase(it);
      sz += dfs(*it);
      it = vis.lower_bound(*it);
    }
    else it++;
  }
  return sz;
}
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mlb upper_bound
#define mub lower_bound
#define smaller(x) order_of_key(x)
#define kth(x) find_by_order(x)


int PhI[maxn];
void ETF()
{
  // Galti ho to ek baar Print kar ke dekh lio
  for (int i = 0; i < maxn; i++)
  {
    PhI[i] = i;
  }
  for (int i = 2; i < maxn; i++)
  {
    if (PhI[i] != i)
    {
      continue;
    }
    for (int j = i; j < maxn; j += i)
    {
      PhI[j] = PhI[j] * (i - 1) / i;
    }
  }
}
int prime[maxn];
void sieve() {
 
  v[0] = 1;
  for (int i = 2; i<maxn; i++) {
    if (!prime[i])
      for (int j = 2 * i; j < maxn; j += i)
        prime[j]++;
  }
}    
#include <bits/stdc++.h>
using namespace std;
#define      M    1000000007
#define      hM   9999999900000001
#define      int long long int
#define      vi vector<int>
#define      vvi vector<vi>
#define      vpi vector<pair<int,int>>
#define      pii pair<int,int>
#define      pb push_back
#define      inf 1e18
#define      ff first
#define      ss  second
#define      line  "\n"
#define      deb(x) cout<<#x<<" "<<x<<endl;
#define      all(x) x.begin(),x.end()
#define      printVec(vec) {for(auto &x : vec) cout << x <<" "; cout << endl; }
const int N = 1e5 + 10;

//int BIT[N];
//void add(int x, int val) {while (x < N)BIT[x] += val, x += x & -x;}
//int sum(int x) {return x ? BIT[x] + sum(x - (x & -x)) : 0;}


void runcases(int T)
{

  //int n;
  //cin >> n;
  //vi v(n);
  //for (int i = 0; i < n; i++) {
  //cin >> v[i];
  //}



  //cout << "Case #" << T << ": ";
}

int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
#ifndef ONLINE_JUDGE
  // freopen("inputf.txt", "r", stdin);
  // freopen("outputf.txt", "w", stdout);
#endif
  int T = 1;
  //cin >> T;
  for (int t = 1; t <= T; t++) {
    runcases(t);
  }

  return 0;
}

