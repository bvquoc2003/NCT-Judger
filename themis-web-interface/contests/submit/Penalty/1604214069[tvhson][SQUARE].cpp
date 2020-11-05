#include <bits/stdc++.h>
#define int long long

using namespace std;
int NM = 10000000;

int k;
vector <int> t;

void Init() {
    int s = 0;
    t.push_back(0);
    // if (abs(k) <= 100000) NM = 10000;
    for (int i = 1; i <= NM; i += 2) {
        s += i;
        t.push_back(s);
    }
}

int32_t main() {
    freopen("SQUARE.INP","r",stdin);
    freopen("SQUARE.OUT","w",stdout);
    scanf("%lld", &k);
    Init();
    int res = 0;
    bool ok = false;
    int j = lower_bound(t.begin(), t.end(), -k) - t.begin();
    for (int i = j; i < t.size(); i++) {
        if (k + t[i] < 0) continue;
        int l = lower_bound(t.begin(), t.end(), k + t[i]) - t.begin();
        if (t[l] == k + t[i]) {
            ok = true;
            res = k + t[i];
            break;
        }
    }
    res = sqrt(res);
    if (ok) printf("%lld", res);
    else printf("none");
}