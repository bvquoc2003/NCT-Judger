#include <bits/stdc++.h>

using namespace std;
const int N = 100005;

int n;
int a[N];
string s;
int ans[N];

void Solve() {
    deque <int> d;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'W') ans[i] = d.size();
        while (d.size() && a[i] > a[d.back()]) d.pop_back();
        d.push_back(i);
    }
    d.clear();
    for (int i = n ; i >= 1; i--) {
        if (s[i] == 'E') ans[i] = d.size();
        while (d.size() && a[i] > a[d.back()]) d.pop_back();
        d.push_back(i);
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("CAMERA.INP","r",stdin);
    freopen("CAMERA.OUT","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> s;
    s = " " + s;
    Solve();
    
}