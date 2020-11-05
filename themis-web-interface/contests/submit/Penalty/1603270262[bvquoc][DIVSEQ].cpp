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

const int N = 50004;
int d, n, a[N];
int psum[N];
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
        FOR(l,1,n) FOR(r,l,n) {
            if ((psum[r]-psum[l-1]) % d == 0) res++;
        }
        cout << res << endl;
    }
    return 0;
}