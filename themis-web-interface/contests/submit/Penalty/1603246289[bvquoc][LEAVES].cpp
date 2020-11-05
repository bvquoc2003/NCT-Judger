#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
// #define int long long
using namespace std;

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

using ii = pair <int, int>;
using ld = long double;
using ll = long long;

const int N = 100005;
int n, p_id[N];
ii a[N];
ll S, psum[N];

ll sum(int l, int r) {
    if (l>r) return 0;
    return psum[r] - psum[l-1];
}
ll sum_id (int l, int r) {
    if (l>r) return 0;
    return p_id[r] - p_id[l-1];
}
ll P(int k) {
    ll Min_P = LLONG_MAX;
    FOR(l,1,n-k+1) {
        int r = l+k-1;
        ll cur = sum_id(l,r);
        cur *= 1LL*k;
        cur += sum(l,r);
        Min_P = min(cur, Min_P);
    }
    return Min_P;
}

ll solve(int k) {
    ll cur = 0;
    FOR(i,1,k) {
        cur += (ll)a[i].first + 1LL*a[i].second*k;
        if (cur > S) break;
    }
    return cur;
}
int K;
signed main(void) {
    FastIO;
    freopen("LEAVES.INP","r",stdin);
    freopen("LEAVES.OUT","w",stdout);
    Read(n); Read(S);
    FOR(i,1,n) {
        Read(a[i].first);
        a[i].second = i;
    }


    int res = 0, cost = 0;
    int l = 0, r = n;
    while (l <= r) {
        K = l + (r-l)/2;
        sort(a+1, a+1+n,[](const ii &A, const ii &B) {
            return A.first + A.second*K < B.first + B.second*K;
        });
        if (solve(K) <= S) {
            res = max(res, K);
            l = K+1;
        } else r = K-1;
    }

    K = res;
    sort(a+1, a+1+n,[](const ii &A, const ii &B) {
        return A.first + A.second*K < B.first + B.second*K;
    });
    Write(res); putchar(' ');
    if (res) Write(solve(res));
    // else putchar('0');
    return 0;
}