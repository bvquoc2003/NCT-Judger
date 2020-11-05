#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, s;
int a[45];
int f[100005];
int sum;
int res;

vector <int> k;
map <int, int> q;

void Try(int i, int n, int x) {
    for (int j = 0; j <= 1; j++) {
        sum += a[i] * j;
        // cout << s << endl;
        if (i == n) {
            if (!x) k.push_back(sum);
            else q[sum]++;
        } else Try(i + 1, n, x);
        sum -= a[i] * j;
    }
}

void Solve() {
    for (int x : k) {
        int Sum = s - x;
        res += q[Sum];
    }
    printf("%lld", res);
}

int32_t main() {
    freopen("Travel.INP", "r", stdin);
    freopen("Travel.OUT", "w", stdout);
    scanf("%lld%lld", &n, &s);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    Try(1, n/2, 0);
    Try(n/2 +1, n, 1);
    // for (int x : k) cout << x << endl;
    Solve();
}