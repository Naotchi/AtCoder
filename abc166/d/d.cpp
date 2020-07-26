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
    ll x; cin >> x;
    for(ll i=-200; i<=200; i++) {
        for(ll j=-200; j<=200; j++) {
            if(i*i*i*i*i - j*j*j*j*j == x) {
                cout << i << ' ' << j << endl;
                return 0;
            }
        }
    }
}
