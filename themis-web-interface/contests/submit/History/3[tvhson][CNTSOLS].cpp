#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int T;
ll cnt[50];
int U, d, m, n;
int now, i, j, k;
int ans;

ll MOD = 1000000007;

ll Luythuy(ll a, ll b, ll m)
{
	if(b == 0) return 1%m;

	ll x = Luythuy(a, b/2, m);
	x = (x*x)%m;

	if(b&1) x = (x*a)%m;

	return x;
}

void Solve() {
    scanf("%d%d%d%d", &U, &d, &m, &n);

	memset(cnt, 0, sizeof(cnt));

	for(i = 0; i < n; i++) {
		now = Luythuy(i, d, n);
		if(i <= U)
			cnt[now] += (U - i)/n + 1;
	}
	ans = 0;
	for(i = 0; i < n; i++)
	for(j = 0; j < n; j++)
	for(k = 0; k < n; k++) {
		if( (i + j + k)%n == m%n ) {
	    	ans += (cnt[i]*((cnt[j]*cnt[k])%MOD))%MOD;
			ans %= MOD;
		}
	}
	printf("%d\n", ans);
}

int main() {
    freopen("CNTSOLS.INP","r",stdin);
    freopen("CNTSOLS.OUT","w",stdout);

	scanf("%d", &T);

	while(T--) {
		Solve();
	}

	return 0;
}
