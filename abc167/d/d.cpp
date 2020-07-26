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
    ll n, k; cin >> n >> k;
    int a[n]; rep(i, n) {cin >> a[i]; a[i]--;}
    vector<int> seen(n);
    deque<int> q;
    int cur = 0;
    while(1) {
        if(seen[cur]) {
            // while(q.front() != cur && k > 0) {q.pop_front(); k--;}
            // if(k == 0) cout << q.front() + 1 << endl;
            // else cout << q[k % q.size()] + 1 << endl;
            while(q.front() != cur) {
                if(k == 0) {
                    cout << q.front() + 1 << endl;
                    return 0;
                }
                q.pop_front();
                k--;
            }
            cout << q[k % q.size()] + 1 << endl;
            return 0;
        }
        seen[cur] = 1;
        q.push_back(cur);
        cur = a[cur];
    }
}
