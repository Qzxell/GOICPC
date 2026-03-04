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
#define rall(v) (v).rbegin(),(v).rend()
#define f(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
	int n,k;
	cin >> n >> k;
	vi v(n);
	f(i,0,n) cin >> v[i];

	int mod = 1e9 + 7;
	vector<vector<ll>> dp(64,vector<ll>(n+2,0));// index 1
	dp[63][0] = 1;
	f(i,0,n){
		for(int j = 63; j >= 0;j--){
			ll x = dp[j][i];
			dp[j&v[i]][i+1] = (dp[j&v[i]][i+1] + x)%mod;
			dp[j][i+1] = (dp[j][i+1] + x)%mod;
		}
	}
	ll ans = 0;
	auto bi = [&](int k){
		int c = 0;
		f(i,0,30)if((k>>i)&1)c++;
		return c;
	};

	for(int j = 0; j < 64;j++)if(bi(j) == k){
		if(j == 63) ans = (ans + dp[j][n] - 1 + mod)%mod;
		else ans = (ans + dp[j][n])%mod;
	}
	cout << ans << ln;


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
