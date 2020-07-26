#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;
const int MAX = 510000;
const ll MOD = 998244353;


ll binarypow(ll a, ll n, ll mod) {
  ll res = 1;
  while(n > 0) {
    if(n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

ll fac[220000], finv[220000];

fac[0] = 1;
Rep(i, 1, 220000) fac[i] = fac[i-1] * i % MOD;
finv[220000 - 1] = binarypow(fac[220000 - 1], MOD-2, MOD);
for(ll i=220000-2; i>-1, i--) finv[i] = finv[i+1] * (i+1) % MOD;

ll COM(ll n, ll k) {
    return fac[n] * finv[k] % MOD * finv[n-k] % MOD;
}

ll binarypow(ll a, ll n, ll mod) {
  ll res = 1;
  while(n > 0) {
    if(n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main() {
    ll n, m, k; cin >> n >> m >> k;
    COMinit();
    ll ans = 0;
    rep(i, k+1) ans += COM(n-1, i) * m % MOD * binarypow(m-1, n-i-1, MOD) % MOD;
    cout << ans % MOD << endl;
}