#include <bits/stdc++.h>
#define int long long

using namespace std;

int a, b, c, d;
int res;


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("NPAIRS.INP","r",stdin);
    freopen("NPAIRS.OUT","w",stdout);
    cin >> a >> b >> c >> d;
    res = abs(a*d - b*c) - __gcd(a,c) - __gcd(b,d) + 1;;
    cout << res;
}