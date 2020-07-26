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


int num(int x) {
    int ans = 0;
    while(x != 0) {
        bitset<100000> y = x;
        int cnt = y.count();
        while(cnt > 0) {

        }
        ans++;
    }
    return ans;
}

int main() {
    int n; cin >> n;
    bitset<100000> x; cin >> x;
    for(int i=1; i<=n; i++) {
        bitset<100000> y = x;
        y[n-i].flip();
        int z = (int)y.to_ulong();
        cout << num(z) << endl;
    }
}
