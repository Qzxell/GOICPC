#include <bits/stdc++.h>

using namespace std;

using ii = pair<int,int>;
using vii = vector<ii>  ;
using vi = vector<int>  ;
#define ln  '\n'
#define ll long long
#define pb push_back
#define fi first
#define se second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
	int n;
	cin >> n;
	vi v(n);
	f(i,0,n)cin >> v[i];
	if (n <= 2 ) {
		cout << 0 << ln;
		return;
	}
	ll ans = 0;
	sort(all(v));
	vector<ll> ps(n,0);
	for(int i = 1 ; i < n;i++){
		ps[i] += ps[i-1] + v[i];
	}
	for(int i = 2 ; i < n;i++){
		int m = i-1;
		ans += m*1ll*v[i] - ps[i-2];
	}
	cout << -ans << ln;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	cin >> tt;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
