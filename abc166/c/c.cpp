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


int main() {
    ll n, m; cin >> n >> m;
    vector<ll> h(n); rep(i, n) cin >> h[i];
    vector<vector<ll>> g(n);
    rep(i, m) {
        ll a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ll ans = 0;
    rep(i, n) {
        bool fl = 1;
        for(ll x : g[i]) if(h[i] <= h[x]) fl = 0;
        if(fl) ans++;
    }
    cout << ans << endl;
}