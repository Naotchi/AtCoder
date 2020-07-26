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
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    if(a[0] == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll ans = 1;
    rep(i, n) {
        if((ll)pow(10, 18) / ans < a[i]) {
            cout << -1 << endl;
            return 0;
        }
        ans *= a[i];
    }
    cout << ans << endl;
}