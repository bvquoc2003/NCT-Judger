#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
// #define int long long
using namespace std;

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 1003, INF = INT_MAX;
int n, T, a[N];
int res = INF;

bool x[21];
void Try(int idx) {
    if (idx > n) {
        int cur = 0, cost = 0;
        FOR(i,1,n) {
            if (x[i]) {
                cur -= T;
                if (cur < 0) return;
            } else {
                cur += a[i];
                if (cur < 0) return;
                cost++; 
            }
        }
        res = min(cost, res);
        return;
    }
    FOR(select, 0, 1) {
        x[idx] = select;
        Try(idx+1);
    }
}

signed main(void) {
    FastIO;
    freopen("GAMESHOW.INP","r",stdin);
    freopen("GAMESHOW.OUT","w",stdout);
    cin >> n >> T;
    FOR(i,1,n) cin >> a[i];
    if (n <= 20) {
        Try(1);
        if (res == INF) res = -1;
        cout << res;
        exit(0);
    }
    return 0;
}