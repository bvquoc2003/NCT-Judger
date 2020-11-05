#include<bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
using namespace std;
typedef long long LL;

LL BIGMOD(LL a, LL b, LL m)
{
	if(b == 0) return 1%m;

	LL x = BIGMOD(a, b/2, m);
	x = (x*x)%m;

	if(b&1) x = (x*a)%m;

	return x;
}
LL MOD = 1000000007;
int main()
{
    freopen("cntsols.inp","r",stdin);
    freopen("cntsols.out","w",stdout);
	int T;
	LL cnt[50];
	int upper, d, m, n;
	int now, i, j, k;
	int ans;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d %d %d", &upper, &d, &m, &n);
		memset(cnt, 0, sizeof(cnt));
		for(i = 0; i < n; i++)
		{
			now = BIGMOD(i, d, n);

			if(i <= upper)
				cnt[now] += (upper - i)/n + 1;
		}
		ans = 0;
		for(i = 0; i < n; i++)
			for(j = 0; j < n; j++)
				for(k = 0; k < n; k++)
				{
					if( (i + j + k)%n == m%n )
					{
						ans += (cnt[i]*((cnt[j]*cnt[k])%MOD))%MOD;
						ans %= MOD;
					}
				}

		printf("%d\n", ans);
	}

	return 0;
}
