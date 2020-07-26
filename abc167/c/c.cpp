#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;

int main() {
    int n, m, x; cin >> n >> m >> x;
    int c[n];
    int a[n][m];
    rep(i, n) {
        cin >> c[i];
        rep(j, m) cin >> a[i][j];
    }
    ll ans = INF;
    rep(i, (1<<n)) {
        ll cost = 0, prof[m] = {0};
        rep(j, n) {    
            if(i & (1<<j)) {
                cost += c[j];
                rep(k, m) prof[k] += a[j][k];
            }
        }
        bool fl = 0;
        rep(j, m) if(prof[j] < x) fl = 1;
        if(fl) continue;
        chmin(ans, cost);
    }
    cout << (ans == INF ? -1 : ans) << endl;
}