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
    int x; cin >> x;
    int ans;
    if(x < 600) ans = 8;
    else if(x < 800) ans = 7;
    else if(x < 1000) ans = 6;
    else if(x < 1200) ans = 5;
    else if(x < 1400) ans = 4;
    else if(x < 1600) ans = 3;
    else if(x < 1800) ans = 2;
    else ans = 1;
    cout << ans << endl;
}
