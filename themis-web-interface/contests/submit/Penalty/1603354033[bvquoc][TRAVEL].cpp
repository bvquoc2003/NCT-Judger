#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
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

const int N = 40;
int n, a[N];
ll S, res = 0;
multiset <int> Set;
bool x[22];

void Try(int i, int n, int d) {
    if (i == n) {
        int cur_S = 0;
        FOR(i,0,n-1) {
            if (x[i]) {
                cur_S += a[i+d];
            }
        }
        if (d != 0) Set.insert(cur_S);
        else res += Set.count(S-cur_S);
        return;
    }
    FOR(j,0,1) {
        x[i] = j;
        if (i<n) Try(i+1,n,d);
    }
}

signed main(void) {
    FastIO;
    freopen("TRAVEL.INP","r",stdin);
    freopen("TRAVEL.OUT","w",stdout);
    Read(n); Read(S);
    FOR(i,0,n-1) Read(a[i]);
    Try(0,n-(n/2),(n/2));
    Try(0,n/2,0);
    Write(res);
    return 0;
}