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
	int n,C;
	cin >> n >> C;
	
	ll inf = -(1ll<<60);
	vector<pair<ll,int>> dp(C+1,{inf,0});

	dp[0] = {0,0};
	f(i,0,n){
		int vv,ww,mm;
		cin >> vv >> ww >> mm;
		vector<pair<ll,int>> ndp = dp;
		for(int j = 0; j <= C;j++){
			if(j + ww <= C and ndp[j].fi != inf){
				if(ndp[j+ww].fi != inf){
					if(ndp[j+ww].fi < ndp[j].fi + vv and ndp[j].se < mm){
						ndp[j+ww].fi = ndp[j].fi + vv ;
						ndp[j+ww].se = ndp[j].se + 1;
					}
				} else{
					if(ndp[j].se + 1 > mm)continue;
					else{
						ndp[j + ww].fi = max(ndp[j+ww].fi,ndp[j].fi + vv);
						ndp[j+ww].se = ndp[j].se + 1;
					}
				}
			}
		}
		swap(dp,ndp);
		f(j,0,C+1){
			if(dp[j].fi == inf)cout << -1 << ' ';
			else cout << dp[j].fi << ' ' ;
			dp[i].se = 0;
		}
		cout << ln;
	}
	ll ans = 0;
	f(i,0,C+1){
		if(dp[i].fi != inf)ans = max(ans,dp[i].fi);
	}
	cout << ans;


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt = 1;
	int test = 1;
	while (tt--){
		so(test++);
	}
	return 0;
}
