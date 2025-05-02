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
	vector<ll> dp(C+1,inf);//dp[wight] := max value

	dp[0] = 0;
	f(i,0,n){
		int vv,ww,mm;
		cin >> vv >> ww >> mm;
                multiset<ll> val[ww];
                vector<ll> ndp = dp;
                int cant_groups = (C+1+ww-1)/ww;
                f(j,0,C+1){
                        int group_dp = j/ww;
                        int mod_dp = j%ww;
                        ll value_dp = dp[j] + vv*(cant_groups - group_dp);
                        if(sz(val[mod_dp]) > mm){
                                ll value_pop = dp[j - (mm+1)*ww] + vv*(cant_groups - (group_dp - mm - 1));
                                auto it = val[mod_dp].find(value_pop);
                                if(it != val[mod_dp].end()) val[mod_dp].erase(it);
                        }
                        val[mod_dp].insert(value_dp);
                        ndp[j] = max(ndp[j],*(prev(val[mod_dp].end())) - vv*(cant_groups - group_dp));
                }
                swap(dp,ndp);
	}
	ll ans = 0;
	f(i,0,C+1){
		ans = max(dp[i],ans);
	}
	cout << ans << ln;


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
