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
    int n; cin >> n;
    vector<bool> b(1000001);
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int cnt = 0;
    rep(i, n) if(a[i] == 1) cnt++;
    if(cnt == 1) {
        cout << 1 << endl;
        return 0;
    }
    if(cnt > 1) {
        cout << 0 << endl;
        return 0;
    }
    rep(i, n) {
        int x = 2;
        while(a[i]*x <= 1000000) {
            b[a[i]*x] = 1;
            x++;
        }
    }
    vector<int> d(1000001);
    rep(i, n) d[a[i]]++;
    rep(i, 1000001) if(d[i] > 1) b[i] = 1;
    int ans = 0;
    rep(i, n) if(!b[a[i]]) ans++;
    cout << ans << endl;
}
