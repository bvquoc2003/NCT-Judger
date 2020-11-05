#include <bits/stdc++.h>
#define int long long

using namespace std;

int T;
bool mark[325005];
vector <int> cur;
void Init() {
    mark[1]=true;
    for (int i = 2; i <= 325000; i++) {
        if (mark[i]) continue;
        for (int j = i * 2; j * j <= 325000; j+=i) {
            mark[j] = true;
        }
    }
    
    for (int i = 1; i <= 325000; i++) if (!mark[i] && i != 3) cur.push_back(i);
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
            int k = u * u * 9;
            if (k % 3 != 0) continue;
            if (k >= a && k <= b) res++;
            if (k > b) break;
        }
        printf("%lld\n", res);
    }
}