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

int main() {
    ll n; cin >> n;
    ll ans = 0;
    for(auto x : prime_factorize(n)) {
        ll a = 0, b = 1;
        while(x.second - b >= 0) {x.second -= b; b++; a++;}
        ans += a;
    }
    cout << ans << endl;
}
