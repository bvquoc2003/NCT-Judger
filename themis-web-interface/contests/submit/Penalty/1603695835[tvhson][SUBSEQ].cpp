#include <bits/stdc++.h>

using namespace std;
const int NM = 100005;

int  n, Sum; 
int f[NM];
int res;
pair <int, int> a[1005];
vector <int> b;

int32_t main() {
    freopen("SUBSEQ.INP", "r", stdin);
    freopen("SUBSEQ.OUT", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
        Sum += a[i].first;
    }

    sort(a+1, a+n+1);

    f[0] = -1;
    for (int i = n; i >= 1; i--) {
        for (int j = Sum; j >= a[i].first; j--) {
            if (f[j] == 0 && f[j - a[i].first] != 0) {
                f[j] = i;
                if (j > Sum/2 && j - a[i].first <= Sum/2) res = max(res, j);
            }
        }
    }

    while (res) {
        b.push_back(a[f[res]].second);
        
        res -= a[f[res]].first;
    }

    printf("%d\n", b.size());
    for (int x : b) printf("%d ", x);
    return 0;
}
