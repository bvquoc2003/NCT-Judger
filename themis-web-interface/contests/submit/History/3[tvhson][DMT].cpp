#include <bits/stdc++.h>
#define int long long

using namespace std;
const int NM = 1e7+5;

int T;
bool mark[NM];
vector <int> cur;

void Init() {
    mark[1]=true;
    for (int i = 2; i * i <= NM; i++) {
        if (mark[i]) continue;
        for (int j = i * i; j <= NM; j+=i) {
            mark[j] = true;
        }
    }
    
    for (int i = 1; i <= NM; i++) if (!mark[i] && i != 3) cur.push_back(i);
}

int32_t main() {
    freopen("DMT.INP","r",stdin);
    freopen("DMT.OUT","w",stdout);    
    scanf("%lld", &T);

    Init();

    while (T--) {
        int a, b;
        scanf("%lld%lld", &a, &b);
        int res = 0;

        for (int u : cur) {
            int k = (u * u) * 9;
            if (k % 3 != 0) continue;
            if (k >= a && k <= b) res++;
            if (k > b) break;
        }
        printf("%lld\n", res);
    }
}