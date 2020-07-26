#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1000000000;
const int MOD = MM + 7;
const int MAX = 510000;
double pi = 3.141592653589793238;
#define rep(i, n) for(ll i=0; i<n; i++)
#define Rep(i, j, n) for(ll i=j; i<n; i++)
#define all(vec) vec.begin(), vec.end()
template<class T> inline bool chmin(T& a, T b) {if(a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if(a < b) {a = b; return true;} return false;}
const ll INF = 1LL << 60;

int main() {
    cout << setprecision(15) << fixed;
    double a, b, h, m; cin >> a >> b >> h >> m;
    double min = 2 * pi * m / 60.;
    double hour = 2 * pi * h / 12.;
    hour += min / 12.;
    double arg = abs(min - hour);
    chmin(arg, 2*pi - arg);
    cout << sqrt(a*a + b*b - (double)2*a*b*cos(arg)) << endl;
}
