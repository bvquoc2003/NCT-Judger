#include <bits/stdc++.h>

using namespace std;
const int N = 10005;

int n, k, q, p;
int a[10005];
int f[N][10005];
int Tr[N][10005];
int C[N][10005];

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("FARM.INP","r",stdin);
    freopen("FARM.OUT","w",stdout);
    cin >> n >> k >> q >> p;
    int K = n / k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j <= n; j++) {
            Tr[i][j] = j;
            if (j <= k) {
                if (f[i][j - 1] > a[j]) {
                    Tr[i][j] = Tr[i][j - 1];
                    f[i][j] = f[i][j - 1];
                    C[i][j] = C[i][j - 1];
                } else {
                    f[i][j] = a[j];
                    C[i][j] = j;
                }
                continue;
            } 
            if (f[i][j - 1] > a[j] + f[i - 1][j - k]) {
                Tr[i][j] = Tr[i][j - 1];
                f[i][j] = f[i][j - 1];
                C[i][j] = C[i][j - 1];
            } else {
                Tr[i][j] = j - k;
                C[i][j] = j;
                f[i][j] = f[i - 1][j - k] + a[j];
            }
        }
    }
    
    int ans = 0;
    // cout << K;
    // cout << f[K][n];
    for (int i = 1; i <= K; i++)  {
        priority_queue <int> pq;
        int x = i, y = n;
        int res = 0;
        // cout << endl;
        while (x != 0) {
            pq.push(a[C[x][y]]);
            // cout << a[C[x][y]] << " ";
            x--;
            y = Tr[x][y];
        }
        int l = q;
        while (l != 0 && pq.size()) {
            if (l >= p) {
                res += p * pq.top();
                l -= p;
            } else {
                res += l * pq.top();
                l = 0;
            }
            pq.pop();
        }
        ans = max(ans, res);
    }
    cout << ans;
}