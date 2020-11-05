#include <bits/stdc++.h>
#define int long long

using namespace std;
const int NM = 1e5+5;

int n, S;
int a[NM];

int check(int x) {
    priority_queue <int, vector<int>, greater <int> > pq;
    int s = 0;
    int t = 0;
    for (int i = 1; i <= n; i++) {
        s = a[i] + i * x;
        pq.push(s);
    }
    while (pq.size() > n - x) {
        t += pq.top();
        pq.pop();
    }
    return t;
}

int32_t main() {
    freopen("LEAVES.INP","r",stdin);
    freopen("LEAVES.OUT","w",stdout);
    scanf("%d%d", &n, &S);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int l = 0, r = n;
    int res = 0;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        int cur = check(mid);
        if (cur <= S) {
            res = mid;
            ans = cur;
            l = mid + 1; 
        } else r = mid - 1;
    }
    printf("%lld ", res);
    if (res) printf("%lld", ans);
}