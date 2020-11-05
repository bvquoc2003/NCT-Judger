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

const int N = 100005;
int n, L; 
pair <int, ll> res[N];
struct Data { 
    int id, time, speed;
	bool operator == (const Data &B) {
		return time == B.time;
	}
} a[N];

signed main(void) {
    FastIO;
    freopen("WALKING.INP","r",stdin);
    freopen("WALKING.OUT","w",stdout);
    cin >> n >> L;
    FOR(i,1,n) {
        cin >> a[i].time >> a[i].speed;
        a[i].id = i;
    }
    sort(a+1,a+1+n,[](const Data &A, const Data &B) {
        return (A.time < B.time || (A.time == B.time && A.speed > B.speed));
    });
	FOR(i,1,n) {
		res[i].first = a[i].id;
		res[i].second = 1LL*a[i].time + 1LL*a[i].speed*L;
	}
    
	FOR(i,2,n) res[i].second = max(res[i].second, res[i-1].second);
	sort(res+1, res+1+n);
	FOR(i,1,n) cout << res[i].second << endl;
    return 0;
}