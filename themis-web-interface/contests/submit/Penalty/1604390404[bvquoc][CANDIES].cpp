#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define REP(i, n) for(int i=0, _n=(n); i<_n; i++)
#define ALL(v) (v).begin(), (v).end()
#define BIT(x, i) (((x) >> (i)) & 1)
#define MASK(i) (1LL << (i))
#define endl '\n'
#define int long long
using namespace std;

template<class T> T Abs(const T &x) { return (x < 0 ? -x : x); }
template<class X, class Y>
bool minimize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x > y + eps) {
        x = y;
        return true;
    } else return false;
}
template<class X, class Y>
bool maximize(X &x, const Y &y) {
    X eps = 1e-9;
    if (x + eps < y) {
        x = y;
        return true;
    } else return false;
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int NTEST = 102;
ii q[NTEST];
int LIM = -1;
#define nextFib (fibo.back() + fibo[fibo.size()-2])
vector <int> fibo;

int calc(int x) {
    if (x < 0) return 0;
    int p = -1;
    int l = 0, r = fibo.size() - 1, mid;
    while (l <= r) {
        mid = (l+r) / 2;
        if (fibo[mid] == x) return 1;
        if (fibo[mid] > x) r = mid - 1;
        else {
            maximize(p, mid);
            l = mid + 1;
        }
    }
    return 1 + calc(x - fibo[p]);
}

signed main(void) {
    FastIO;
    freopen("CANDIES.INP","r",stdin);
    freopen("CANDIES.OUT","w",stdout);
    int T; cin >> T;
    REP(i,T) {
        cin >> q[i].first >> q[i].second;
        maximize(LIM, q[i].first);
    }
    fibo.push_back(1);
    fibo.push_back(2);
    while (nextFib <= LIM) fibo.push_back(nextFib);
    
    REP(i,T) {
        int ans = 0, cur;
        FOR(j,1,q[i].first) {
            cur = calc(j);
            if (cur >= q[i].second) ans += cur;
        }
        cout << ans << endl;
    }
    return 0;
}