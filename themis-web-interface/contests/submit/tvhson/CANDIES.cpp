#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int a[N], b[N];
int Max;
vector <int> f;
int T;

int Search(int x) {
    if (x < 0) return 0;
    int y = -1;
    int l = 0, r = f.size() - 1;
    while (l <= r) {
        int mid = (l+r) / 2;
        if (f[mid] == x) return 1;
        if (f[mid] > x) r = mid - 1;
        else {
            y = max(y, mid);
            l = mid + 1;
        }
    }
    return 1 + Search(x - f[y]);
}

int32_t main() {
    freopen("CANDIES.INP","r",stdin);
    freopen("CANDIES.OUT","w",stdout);
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        scanf("%d%d", &a[i], &b[i]);
        Max = max(Max, a[i]);
    }
    f.push_back(1);
    f.push_back(1);
    while (f[f.size() - 1] + f[f.size() - 2] <= Max) f.push_back(f.back() + f[f.size() - 2]);
    
    for (int i = 1; i <= T; i++) {
        int ans = 0;
        for (int j = 1; j <= a[i]; j++) {
            int res = Search(j);
            if (res >= b[i]) ans += res;
        }
        cout << ans << endl;
    }
    return 0;
}