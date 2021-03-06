#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

using ii = pair <int, int>;
using ll = long long;
using ld = long double;

const int N = 50004, D = 1000006;
int d, n, a[N];
int cnt[D], psum[N];
int res;

signed main(void) {
    FastIO;
    freopen("DIVSEQ.INP","r",stdin);
    freopen("DIVSEQ.OUT","w",stdout);
    int T; cin >> T;
    while (T--) {
        cin >> d >> n;
        FOR(i,1,n) {
            cin >> a[i];
            psum[i] = psum[i-1]+a[i];
        }
        res = 0;
        if (n <= 1000) {
            FOR(l,1,n) FOR(r,l,n) {
                if ((psum[r]-psum[l-1]) % d == 0) res++;
            }
        } else {
            FOR(i,0,d-1) cnt[i] = 0; cnt[0] = 1;
            FOR(i,1,n) {
                int x = psum[i]%d; 
                cnt[x]++;
            }
            FOR(i,0,d-1) res += (cnt[i]*(cnt[i]-1));
            res /= 2;
        }
        
        Write(res);
        putchar(endl);
    }
    return 0;
}