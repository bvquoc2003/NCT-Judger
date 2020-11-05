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
using ll = long long;
using ld = long double;

const string INP=".INP", OUT=".OUT";
const string FILENAME="CNTSOLS";
const int mod=1000000007;

template <typename T>
inline void Read(T& x) {
	bool Neg=false;
	char c;
	for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') Neg=!Neg;
	x=c-'0';
	for (c=getchar();c>='0' && c<='9';c=getchar()) x=x*10+c-'0';
	if (Neg) x=-x;
}
template <typename T>
inline void Write(T x) {
	if (x<0) { putchar('-'); x=-x; }
	T p=1;
	for (T temp=x/10;temp>0;temp/=10) p*=10;
	for (;p>0;x%=p,p/=10) putchar(x/p+'0');
}

int U, d, m, N;
int res, s;

inline int pw(int a, int b) {
	if (b == 0) return 1;
	int cur = pw(a,b/2);
	if (b%2 == 0) return (cur*cur)%10;
	return (cur*cur*a)%10;
}

int32_t main() {
	FastIO;
	freopen((FILENAME+INP).c_str(),"r",stdin);
	freopen((FILENAME+OUT).c_str(),"w",stdout);
	int T; Read(T);
	while(T--) {
		Read(U); Read(d); Read(m); Read(N);
		res=0;
        FOR(x,0,U) FOR(y,x,U) FOR(z,y,U) {
			s = pw(x,d) + pw(y,d) + pw(z,d);
			s %= N;
			if (s == m) {
				res++;
				if (x!=y || y!=z || x!=z) res += 2;
				res %= mod;
			}
		}
		Write(res); putchar(endl);
	}
	return 0;
}