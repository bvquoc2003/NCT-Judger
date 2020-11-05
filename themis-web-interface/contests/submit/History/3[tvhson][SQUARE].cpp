#include <bits/stdc++.h>
#define int long long

using namespace std;
int NM = 10000000;

int k;
vector <int> t;

int32_t main() {
    freopen("SQUARE.INP","r",stdin);
    freopen("SQUARE.OUT","w",stdout);
    scanf("%lld", &k);
    if (k == 0) {
        printf("0");
        return 0;
    }
    int K = k;
    if (k < 0) K = -k;
    
    int result = LLONG_MAX;
    for (int i = 1; i * i <= K; i++) {
        if (K % i != 0) continue;
        int j = k / i;
        if ((i + j) % 2 == 0) result = min(result, abs((i + j) / 2));
    }
    
    if (result == LLONG_MAX) printf("none");
    else printf("%lld", result);
}