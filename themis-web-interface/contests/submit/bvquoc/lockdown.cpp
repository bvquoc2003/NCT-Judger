#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
#define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;
using ll = long long;

template <typename T>
inline void Read(T& x) {
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void Write(T x) {
    if (x < 0) { putchar('-'); x = -x; }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

const int N = 502, INF = 1e18;
int n, w[N][N];
unordered_set <int> ke[N];
int d[N][N];

void dijkstra(int s, int k){
    FOR(i,1,n) d[k][i] = INF;
    d[k][s] = 0;
    priority_queue<ii, vector<ii>, greater<ii> > pq;
    pq.push(ii(0, s));

    while (!pq.empty()){
        int u = pq.top().se, du = pq.top().fi;
        pq.pop();
        if (du != d[k][u]) continue;
        for (int v: ke[u]) {
            if (d[k][u] + w[u][v] < d[k][v]){
                d[k][v] = d[k][u] + w[u][v];
                pq.push(ii(d[k][v], v));
            }
        }
    }
}

signed main(void) {
    FastIO;
    freopen("lockdown.inp","r",stdin);  
    freopen("lockdown.out","w",stdout); 
    Read(n);
    FOR(i,1,n) {
        FOR(j,1,n) {
            Read(w[i][j]);
            if (w[i][j]>0) {
                ke[i].insert(j);
                ke[j].insert(i);
            }
        }
    }

    int res = 0;
    dijkstra(1,0);
    for (int u: ke[1]) {
        int tmp = w[1][u];
        w[1][u] = INF;
        dijkstra(1,u);
        int cur = 0;
        FOR(v,1,n) if (d[u][v] > d[0][v]) cur++;
        res = max(res, cur);
        w[1][u] = tmp;
    }
    Write(res);
    return 0;
}