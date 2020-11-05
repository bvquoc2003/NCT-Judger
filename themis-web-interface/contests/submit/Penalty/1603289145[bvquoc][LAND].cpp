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
using ld = long double;
using ll = long long;

const int N = 102;
int n, x, y, z;
int A[N], B[N], dp[1003][1003];
int sz_A = 0, sz_B = 0;
int a[1003], b[1003];

signed main(void) {
    FastIO;
    freopen("LAND.INP","r",stdin);
    freopen("LAND.OUT","w",stdout);
    cin >> n >> x >> y >> z;
    FOR(i,1,n) cin >> A[i] >> B[i];
    FOR(i,1,n) {
        int tmp = A[i];
        while (tmp != 0) {
            a[++sz_A] = i;
            tmp--;
        }
    }

    FOR(i,0,sz_A) dp[i][0] = i*y;
    FOR(i,0,sz_B) dp[0][i] = i*x;
    FOR(i,1,sz_A) FOR(j,1,sz_B) {
        dp[i][j] = min({x+dp[i][j-1], y+dp[i-1][j], dp[i-1][j-1] + z*(abs(a[i]-b[j]))});
    }
    cout << dp[sz_A][sz_B];
    return 0;
}