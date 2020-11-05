#include <bits/stdc++.h>

using namespace std;

string a, b;
int D[10000];
int s = 0;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    freopen("DNA.INP","r",stdin);
    freopen("DNA.OUT","w",stdout);
    cin >> a;
    cin >> b;
    if (a.size() != b.size()) {
        cout << "Different";
        return 0;
    }
    
    D['A'] = 'D';
    D['D'] = 'A';
    D['G'] = 'T';
    D['T'] = 'G';
    for (int i = 0 ; i < a.size(); i++) {
        if (a[i] != b[i]) {
            if (D[a[i]] == b[i] || D[b[i]] == a[i]) s++;
            else {
                cout << "Different";
                return 0;
            } 
        }
    }
    if (s <= 4) cout << "Similar";
    else cout << "Different";
}