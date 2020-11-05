#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define fi first
#define se second
#define FOR(i, a, b) for(int i=a; i<=b; i++)
#define FORD(i, a, b) for(int i=a; i>=b; i--)
#define endl '\n'
using namespace std;

using ii = pair <int, int>;
using ld = long double;
using ll = long long;

string s, x, y;

signed main(void) {
    FastIO;
    freopen("EOE.INP","r",stdin);
    freopen("EOE.OUT","w",stdout);
    cin >> s >> x >> y;
    s.push_back('+');

    bool isOdd = 0, cur = 0, tmp = 1;    
    for (char ch: s)  {
        if (ch == '+' || ch == '-')  {
            tmp *= cur;
            isOdd = isOdd xor tmp;
            tmp = 1;
            continue;
        } 
        if (ch == '*') {
            tmp *= cur; 
            cur = 0;
            continue;
        }
        
        if (ch == 'x' || ch == 'y')  {
            if (ch == 'x') cur = (x == "Odd");
            else cur = (y == "Odd");
            continue;
        }
        cur = (ch-'0') % 2;
    }

    cout << (isOdd ? "Odd" : "Even");
    return 0;
}