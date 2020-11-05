#include<bits/stdc++.h>
using namespace std;

const int maxN = 1e5;
int n;
long long a[maxN], b[maxN];

int main() {
    freopen("game.inp", "r", stdin);
    freopen("game.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(a, a+n);
    sort(b, b+n);

    cout << a[0] + b[0];

    return 0;
}