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
    vector<ll> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    sort(all(a)); sort(all(b));
    ll l, r;
    if(n % 2 == 0) {
        l = a[n/2-1] + a[n/2];
        r = b[n/2-1] + b[n/2];
    }
    else {
        l = a[(n+1)/2-1];
        r = b[(n+1)/2-1];
    }
    cout << r - l + 1<< endl;
}
