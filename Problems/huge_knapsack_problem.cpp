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
        ll n,W;	
        cin >> n >> W;
        set<ll> my_set;
        map<ll,ll> dp;// dp[weight] := max value
        my_set.insert(0);
        dp[0] = 0;
        set<ll> temp;
        f(i,0,n){
                ll v,w;
                cin >> v >> w;
                temp = my_set;
                for(auto x : temp){
                        ll to = x + w;
                        if(to > W)continue;
                        if(temp.count(to)){
                                dp[to] = max(dp[to], dp[x] + v);
                        }else{
                                my_set.insert(to);
                                dp[to] = dp[x] + v;
                        }
                }
        }
        ll ans = 0;
        for(auto x : my_set){
                ans = max(ans,dp[x]);
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
