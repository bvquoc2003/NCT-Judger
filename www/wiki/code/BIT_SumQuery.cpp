#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
// #define int long long
using namespace std;

using ii = pair <int, int>;
using ld = long double;

struct BIT_SumQuery {
    vector<int> bit;  // binary indexed tree
    int n;
    BIT_SumQuery() {}
    BIT_SumQuery(int n) {
        this->n = n;
        bit.assign(n+1, 0);
    }
    void assign (int n) {
        this->n = n;
        bit.assign(n+1, 0);
    }

    BIT_SumQuery(vector<int> a) : BIT_SumQuery(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 1; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx <= n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

signed main(void) {
    FastIO;
    BIT_SumQuery BIT(6);
    BIT.add(1, 3);
    BIT.add(2, 2);
    BIT.add(3, 5);
    BIT.add(4, 6);
    BIT.add(5, 8);
    BIT.add(6, 7);
    // [] = {3, 2, 5, 6, 8, 7}
    cout << BIT.sum(3) << endl;
    cout << BIT.sum(1, 4) << endl;
    cout << BIT.sum(2, 5) << endl;
    cout << BIT.sum(3, 6) << endl;
    cout << BIT.sum(1, 6) << endl;
    cout << BIT.sum(6) << endl;
    return 0;
}