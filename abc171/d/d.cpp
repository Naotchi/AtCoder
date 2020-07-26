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
    ll n; cin >> n;
    vector<ll> v(100001);
    ll sum = 0;
    rep(i, n) {
        ll a; cin >> a;
        v[a]++;
        sum += a;
    }
    int q; cin >> q;
    rep(i, q) {
        ll b, c; cin >> b >> c;
        sum -= b * v[b];
        sum += c * v[b];
        v[c] += v[b];
        v[b] = 0;
        cout << sum << endl;
    }
}
