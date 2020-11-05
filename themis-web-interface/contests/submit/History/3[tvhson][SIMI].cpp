#include <bits/stdc++.h>
#define int long long
using namespace std;

#define N 1000005
int n, z[N];
char a[N];
int res = 0;

void make_z(char a[], int n, int F[]) {
    int L = -1, R = -1;
    F[0] = n;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = i;
            R = i - 1;
            while (R < n - 1 && a[R + 1] == a[R - L + 1]) R++;
            F[i] = R - L + 1;
        } else {
            if (F[i - L] < R - i + 1)
                F[i] = F[i - L];
            else {
                L = i;
                while (R < n - 1 && a[R + 1] == a[R - L + 1]) R++;
                F[i] = R - L + 1;
            }
        }
    }
}

int32_t main() {
    freopen("SIMI.INP","r",stdin);
    freopen("SIMI.OUT","w",stdout);
    gets(a);
    n = strlen(a);
    make_z(a, n, z);
    for (int i = 0; i < n; i++)
        res += z[i];;
    printf("%lld", res);
}