#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ld = long double;
using ll = long long;

int n, x, y, z;
int sz_A, sz_B;
int A[105], a[1005];
int B[105], b[1005];
int dp[1005][1005];

signed main() {
    freopen("LAND.INP","r",stdin);
    freopen("LAND.OUT","w",stdout);
    cin >> n >> x >> y >> z;
    FOR(i,1,n) cin >> A[i] >> B[i];
    FOR(i,1,n) {
        int cur = A[i];
        while (cur) {
            a[++sz_A] = i;
            cur--;
        }
    }
    FOR(i,1,n) {
        int cur =B[i];
        while (cur) {
            b[++sz_B] = i;
            cur--; 
        }
    }
    
    FOR(i,0,sz_A) dp[i][0] = i*y;
    FOR(i,0,sz_B) dp[0][i] = i*x;
    FOR(i,1,sz_A) FOR(j,1,sz_B) {
        dp[i][j]=min({y+dp[i-1][j], x+dp[i][j-1], dp[i-1][j-1]+z*(abs(a[i]-b[j]))});
    }
    cout << dp[sz_A][sz_B];
    return 0;
}