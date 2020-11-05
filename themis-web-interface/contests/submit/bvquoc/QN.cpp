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

int n, t;
vector <int> S(2);
stack <int> cur;

signed main(void) {
    FastIO;
    freopen("QN.INP","r",stdin);
    freopen("QN.OUT","w",stdout);
    cin >> n >> t; S[1] = 1;
    FOR(i,2,n) {
        for (int x: S) {
            int c = (1<<(i-1));
            c ^= x;
            cur.push(c);
        }
        while (cur.size()) {
            S.push_back(cur.top());
            cur.pop();
        }
    }

    int p = 0;
    FOR(i,0,(1<<n)-1) {
        if (S[i] == t) {
            p = i;
            break;
        }
    }
    FOR(i,p+1,(1<<n)-1) cout << S[i] << endl;
    FOR(i,0,p-1) cout << S[i] << endl;
    return 0;
}