#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;

//進数を変換
ll change_base(ll num, ll base) {
    ll dig = 1;
    ll ret = 0;
    while(num > 0) {
        ret += num % base * dig;
        num /= base;
        dig *= 10;
    }
    return ret;
}


//素因数分解
vector<pair<ll, ll>> prime_factorize(ll n) {
    vector<pair<ll, ll>> res;
    for(ll i=2; i*i<=n; i++) {
        if(n % i != 0) continue;
        ll num = 0;
        while(n % i == 0)  {num++; n /= i;}
        res.push_back(make_pair(i, num));
    }
    if(n != 1) res.push_back(make_pair(n, 1));
    return res;
}

//素数判定
bool IsPrime(ll num){
  if (num < 2) return false;
  else if (num == 2) return true;
  else if (num % 2 == 0) return false;
  double sqrtNum = sqrt(num);
  for (ll i = 3; i <= sqrtNum; i += 2){
    if(num % i == 0) return false;
  }
  return true;
}

ll GCD(ll x, ll y) {
    if (y == 0) return x;
    else return GCD(y, x % y);
}

ll LCM(ll x, ll y) {
    return x / GCD(x, y) * y;
}

//nCrの値
ll combination(ll n, ll r) {
  if(r==1)return n;
  else return n * combination(n-1, r-1) / r;
}

//pair型のsecondを優先的にソート
bool sort_by_second (pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

//二分探索
vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

bool isOK(int index, int key) {
    if (a[index] >= key) return true;
    else return false;
}

int binary_search(int key) {
    int left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    int right = (int)a.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    /* どんな二分探索でもここの書き方を変えずにできる！ */
    while (right - left > 1) {
        int mid = left + (right - left) / 2;

        if (isOK(mid, key)) right = mid;
        else left = mid;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    return right;
}

//約数の個数
ll divesor_number(ll n) {
  ll res = 0;
    for(ll i=1; i*i<=n; i++) {
        if(n % i == 0) res += 2;
        if(i * i == n) res--;
    }
    return res;
}

//約数列挙
vector<ll> divisor(ll n) {
  vector<ll> ret;
  for(ll i=1; i*i<=n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i*i != n) ret.push_back(n / i);
    }
  }
  sort(all(ret));
  return (ret);
}

//二分累乗法
ll binarypow(ll a, ll n/*, ll mod*/) {
  ll res = 1;
  while(n > 0) {
    if(n & 1) {
      res *= a;
      //res %= mod;
    }
    a *= a;
    //a %= mod;
    n >>= 1;
  }
  return res;
}

//拡張ユークリッドの互除法
// 非再帰バージョン
ll modinv(ll a, ll m) {
    ll b = m, u = 1, v = 0;
    while (b) {
        ll t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m; 
    if (u < 0) u += m;
    return u;
}

// ax + by = gcd(a, b)となるような (x, y) を求める
// 多くの場合 a と b は互いに素として ax + by = 1 となる (x, y) を求める
ll extGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extGCD(b, a%b, y, x); // 再帰的に解く
    y -= a / b * x;
    return d;
}

// 逆元計算 Fermatの小定理(mが素数、aがmの倍数でない) a^-1 mod.m
ll modinv(ll a, ll m) {
  ll x, y;
  extGCD(a, m, x, y);
  return (x % m + m) % m;
}

//逆元計算　拡張Euclidの互除法(mが素数でなくてもaと互いに素ならばよい)
//const int MAX = 510000;
//const int MOD = 1000000007;
//int main内で　COMinit();　と書くのを忘れないように

ll fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// 二項係数計算(nが大きくkが小さい場合)
ll COM(ll n, ll k){
    ll res = 1;
    Rep(i, n-k+1, n+1) res = res * i % MOD;
    res = res * finv[k] % MOD;
    return res;
}

// DFS
using Graph = vector<vector<int>>;

vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true;
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue;
        dfs(G, next_v);
    }
}

int main() {
    int N, M; cin >> N >> M;

    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    seen.assign(N, false);
    dfs(G, 0);
}