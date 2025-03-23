void dij()
{
	vi dp(n + 3, inf);
	set<vi> st;
	st.insert({0, 1});
	vi parent(n + 3, -1);
	dp[1] = 0;
	while (!st.empty())
	{
		auto it = st.begin();
		int u = (*it)[1];
		st.erase(it);
		// cout << u << " ";
		for (auto x : adj[u])
		{
			int v = x.ff;
			int w = x.ss;
			if (dp[v] > (w + dp[u]))
			{
				st.erase({dp[v], v});
				dp[v] = w + dp[u];
				parent[v] = u;
				st.insert({dp[v], v});
			}
		}
	}
	// cout << dp[n] << endl;
	if (parent[n] == -1 || dp[n] == inf)
	{
		cout << -1 << endl;
		return;
	} else
	{
		int x = n;
		vi res;
		while (x != 1)
		{
			// cout << x << " ";
			res.pb(x);
			x = parent[x];
		}
		res.pb(x);
		reverse(all(res));
		for (int x : res)
		{
			cout << x << " ";
		}
	}
}
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
*******************************************************
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
********************************************************
int __nCr(int n, int r, vector<int>& Fact, int mod) {
  int ans = (((Fact[n] * modInverse(Fact[r], mod)) % mod)
             * modInverse(Fact[n - r], mod)) % mod;
  return ans;
}
*********************************************************
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
****************************************************
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define mlb upper_bound
#define mub lower_bound
#define smaller(x) order_of_key(x)
#define kth(x) find_by_order(x)

*********************************************************************
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
********************************************************
int prime[maxn];
void sieve() {
 
  v[0] = 1;
  for (int i = 2; i<maxn; i++) {
    if (!prime[i])
      for (int j = 2 * i; j < maxn; j += i)
        prime[j]++;
  }
}  
*****************************************************
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
// *******************************************************************
int SGT[4 * N];
void update(int idx, int s, int e, int si, int val)
{
  if (s == e)
  {
    SGT[si] += val;
    return;
  }
  int m = (s + e) / 2;
  if (idx <= m)
    update(idx, s, m, 2 * si + 1, val);
  else update(idx, m + 1, e, 2 * si + 2, val);

  SGT[si] = (SGT[2 * si + 1] + SGT[2 * si + 2]);
}
int q(int l, int r, int s, int e, int si)
{
  if (l > r || l > e || r < s)
    return 0;
  if (s >= l && e <= r)
    return SGT[si];
  int m = (s + e) / 2;
  return q(l, r, s, m, 2 * si + 1) + q(l, r, m + 1, e, 2 * si + 2);
}
******************************************
vector<int> parent, size;
int getp(int u)
{
  return (u == parent[u] ? : u : (parent[u] = getp(parent[u])));
}
int connect(int u, int v) {
  u = get(u);
  v = get(v);
  if (u == v)
    return 1;

  if (size[u] < size[v])
    swap(u, v);

  parent[v] = u;
  size[u] += size[v];
  return 0;
}
*****************************************
