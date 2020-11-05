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
const int N = 300005;
int n, a[N], ans = 0;
int Z[N];

signed main(void) {
    FastIO;
    freopen("DIVSEQ.INP","r",stdin);
    freopen("DIVSEQ.OUT","w",stdout);
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    
    int L = 0, R = 0, x;
    Z[0] = 0;
    FOR(k,2,n) {
        if (k>R) x = 1;
        else x = min(Z[k-L+1],R-k+1)+1;
        while (k+x-1<=n && a[x]==a[x+k-1]) x++;
        Z[k] = x-1;
        if (k+Z[k]-1>=R) {
            L = k;
            R = k+Z[k]-1;
        }
    }
    
    FOR(i,1,n) {
        if (Z[i]==n-i+1) {
            ans = i-1;
            break;
        }
    }

    cout << ans;
    return 0;
}