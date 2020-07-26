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
    bool p[110] = {0};
    int x, n; cin >> x >> n;
    rep(i, n) {
        int a; cin >> a;
        p[a] = 1;
    }
    rep(i, 110) {
        if(!p[x-i]) {
            cout << x-i << endl;
            return 0;
        }
        if(!p[x+i]) {
            cout << x+i << endl;
            return 0;
        }
    }
}
