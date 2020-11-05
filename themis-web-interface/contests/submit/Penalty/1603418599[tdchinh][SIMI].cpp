#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define FOR(i,a,b) for (int i = a; i <= b; i++)
using namespace std;
int L,R,x,Z[1000001];
long long t,n;
string S;
int main()
{
    FastIO;
    freopen("SIMI.INP","r",stdin);
    freopen("SIMI.OUT","w",stdout);
    getline(cin, S);
    S = ' '+S+' '+S;
    n = S.length()-1;
    int L = 0, R = 0, x;
    Z[0] = 0;
    FOR(k,2,n) {
        if (k>R) x = 1;
        else x = min(Z[k-L+1],R-k+1)+1;
        while (k+x-1<=n && S[x]==S[x+k-1]) x++;
        Z[k] = x-1;
        if (k+Z[k]-1>=R) {
            L = k;
            R = k+Z[k]-1;
        }
    }
    for (int i = 1; i <= (n+1)/2+1; i++)
        t = t + Z[i];
    cout << t;
    return 0;
}
