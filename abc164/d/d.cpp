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
    string s; cin >> s;
    int n = s.size();
    vector<int> cnt(2019);
    ll num = 0;
    ll dig = 1;
    cnt[0]++;
    rep(i, n) {
        num += dig * (s[n-i-1] - '0');
        num %= 2019;
        cnt[num]++;
        dig = dig * 10 % 2019;
    }
    ll ans = 0;
    rep(i, 2019) ans += cnt[i] * (cnt[i] - 1) / 2;
    cout << ans << endl;
}
