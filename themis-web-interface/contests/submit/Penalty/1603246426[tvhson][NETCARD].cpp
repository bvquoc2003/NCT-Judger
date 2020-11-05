#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
int n, m;
bool cx[100005];
int b[100005];
vector <ii> a[100005];
set <int> s;
int32_t main() {
    freopen("NETCARD.INP","r",stdin);
    freopen("NETCARD.OUT","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i=1, x, y, z;i<=m;i++) {
        scanf("%d%d%d", &x, &y, &z);
        if (z==1) {
            b[x]=-1;
            b[y]=-1;
            s.insert(x);
            s.insert(y);
        } else {
            a[x].push_back(ii(y,z));
            a[y].push_back(ii(x,z));
        }
    }
    for (int x : s) {
        for (int i=0;i<a[x].size();i++) {
            int y=a[x][i].first;
            int z=a[x][i].second;
            if (z==0) b[y]=-2;
        }
    }
    for (int i=1;i<=n;i++) printf("%d ", b[i]+2);
}