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

int N, M, Q, a[50], b[50], c[50], d[50];
int A[11];
int ans = 0;

void dfs(int n) {
    if(n == N) {
        int can = 0;
        rep(i, Q) if(A[b[i]] - A[a[i]] == c[i]) can += d[i];
        chmax(ans, can);
        return;
    }
    Rep(i, A[n], M+1) {
        A[n+1] = i;
        dfs(n+1);
    }
}

int main() {
    cin >> N >> M >> Q;
    rep(i, Q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    A[0] = 1;
    dfs(0);
    cout << ans << endl;
}