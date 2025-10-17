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
        int n,x;
        cin >> n >> x;
        vi w(n);
        f(i,0,n)cin >> w[i];
        vii dp((1<<n) + 5,{21,0});
        dp[0] = {1,0};
        f(mask,0,(1<<n)){
                f(i,0,n)if((mask>>i)&1){
                        int prev_k = dp[mask^(1<<i)].fi;
                        int prev_wei = dp[mask^(1<<i)].se;
                        if(prev_k == 21)continue;
                        if(prev_wei + w[i] <= x)dp[mask] = min(dp[mask],{prev_k,prev_wei + w[i]});
                        else dp[mask] = min(dp[mask],{prev_k + 1,w[i]});
                }
        }
        cout << dp[(1<<n)-1].fi << ln;
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


