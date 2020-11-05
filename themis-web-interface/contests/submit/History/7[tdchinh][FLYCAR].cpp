#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr) ; cout.tie(nullptr);
#define ft first;
#define sc second;
#define endl '\n'
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
using namespace std;
const int N = 402, INF = INT_MAX;
long long n,k,h[N],f[N][N],s[N],maxz,tong;
long long M[N][N];
int z(int l, int r)
{
    if (l>r) return INF;
    return s[r]-s[l-1];
}
int Max(int u, int v) {
    int k = log2(v-u+1);
    return max(M[u][k], M[v-(1<<k)+1][k]);
}
int dp(int n, int k) {
    if (f[n][k] != INF) return f[n][k];
    int cur = INF;
    FOR(j,0,n-1) {
        cur = min(cur, dp(j,k-1) + (n-j)*Max(j+1,n) - z(j+1,n));
    }
    return f[n][k] = cur;
}
int main()
{
    FastIO;
    freopen("FLYCAR.INP","r",stdin);
    freopen("FLYCAR.OUT","w",stdout);
    cin >> n >> k;
    FOR(i,1,n) {
        cin >> h[i];
        s[i] = s[i-1] + h[i];
    }
    FOR(i,0,N-1) FOR(j,0,N-1) f[i][j] = INF;
    FOR (i,0,k) f[0][i] = 0;
    maxz = -INF, tong = 0;
    FOR(i,0,n)
    {
        maxz = max(h[i],maxz);
        tong += h[i];
        f[i][0] = i*maxz - tong;
    }
    FOR(i,1,n) M[i][0] = h[i];
    for (int k=1; (1<<k)<=n; k++)
        for (int i=1; i+(1<<k)-1<=n; i++)
            M[i][k] = max(M[i][k-1], M[i+(1<<(k-1))][k-1]);
    cout << dp(n,k);
    return 0;
}
