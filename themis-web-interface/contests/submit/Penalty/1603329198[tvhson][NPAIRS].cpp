#include <bits/stdc++.h>

using namespace std;

double a, b, c, d;
int res;
double eps = 1e-6;

bool ep(double a, double b) {
    return abs(a - b) < eps;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    freopen("NPAIRS.INP","r",stdin);
    freopen("NPAIRS.OUT","w",stdout);
    cin >> a >> b >> c >> d;

    double x = 0.001, y = 1.0;
    for (double i = x; i < y; i += x) {
        for (double j = x; j < y; j += x) {
            
            double A = a * i;
            double B = b * j;
            double C = c * i;
            double D = d * j;

            double SA = A + B;
            double SB = C + D;
            
            int inA = (int) (SA);
            int inB = (int) (SB);

            A = (double) (inA);
            B = (double) (inB);
            // if ( abs(i - 0.25) < eps  && abs(j - 0.375) < eps) {
            //     cout << i << " " << j << " " << SA << " " << SB <<endl;
            //     cout<< A << " " << B << endl;
            //     return 0;
            // }
            if (ep(A, SA) && ep(B, SB)) res++;
        }
    }
    cout << res;
}