#include <bits/stdc++.h>

using namespace std;

int n;
int a[1000005];
int32_t main() {
    freopen("SHOPSIGN.INP","r",stdin);
    freopen("SHOPSIGN.OUT","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    deque <int> s;
    int l = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        while (s.size() && a[i] <= a[s.back()]) s.pop_back();
        s.push_back(i);
        while (s.size() && i - l >= a[s.front()]) {
            l = s.front();
            res = max(res, a[l]);
            s.pop_front();
        }
    }
    printf("%d", res);
}