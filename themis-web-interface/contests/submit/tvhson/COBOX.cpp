#include <bits/stdc++.h>

using namespace std;

struct data {
    int x, y, id;
};
data a[100005];
int c[100005];
int cnt[100005];
int n;
vector <int> d;

bool cmp(const data &u, const data &v) {
    return (u.x < v.x || (u.x == v.x && u.y < v.y));
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("BOX2.INP","r",stdin);
    freopen("BOX2.OUT","w",stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        bool ok = false;
        for (int j = 0; j < d.size(); j++) if (a[i].x > a[d[j]].x && a[i].y > a[d[j]].y) {
            c[i] = d[j];
            cnt[i] += cnt[d[j]] + 1;
            d[j] = i;
            ok = true;
            break;
        }
        if (ok == false) {
            d.push_back(i);
        }
    }
    cout << d.size() << endl;
    int k = 0;
    while (k < d.size()) {
        cout << cnt[d[k]] + 1 << " ";
        int j = d[k];
        while (j != 0) {
            cout << a[j].id <<" ";
            j = c[j];
        }
        cout << endl;
        k++;
    }
}