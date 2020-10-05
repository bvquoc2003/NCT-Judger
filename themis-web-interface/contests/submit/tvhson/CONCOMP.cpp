#include <bits/stdc++.h>

using namespace std;

int n, m;
typedef pair <int, int> ii;
vector <ii> a[2002];
int k;
bool cx[50005][2002];
void BFS(int ui, int c, int x, int y) {
    queue <int> d;
    d.push(ui);
    cx[c][ui]=true;
    while (d.size()) {
        int u=d.front();
        d.pop();
        for (int i=0;i<a[u].size();i++) {
            
            int v=a[u][i].second;
            if (cx[c][v]) continue;
            if (a[u][i].first>=x && a[u][i].first<=y) continue;
            cx[c][v]=true;
            d.push(v);
        }
    }
}
int32_t main() {
    freopen("CONCOMP.INP","r",stdin);
    freopen("CONCOMP.OUT","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i=1, x, y;i<=m;i++) {
        scanf("%d%d", &x, &y);
        a[x].push_back(ii(i,y));
        a[y].push_back(ii(i,x));
    }
    scanf("%d", &k);
    while (k--) {
        int x, y;
        scanf("%d%d", &x, &y);
        int res=0; 
        for (int i=1;i<=n;i++) {
            if (!cx[k][i]) {
                BFS(i,k,x,y);
                res++;
            }
        }
        printf("%d\n", res);
    }
    
}