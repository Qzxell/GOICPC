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
#define F(i, a, b)  for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a)  for(ll i = (ll)a - 1; i >= (ll)b; i--)

void so(int test){
        int n,W;
        cin >> n >> W;
        ll inf = -(1ll<<60);
        vector<ll> dp(W+1,inf);// dp[i] := max value with weight i
        dp[0] = 0;
        F(x,0,n){
                int v,w;
                cin >> v >> w;
                F(i,0,W+1)if(dp[i] != inf and i + w <= W){
                        dp[i+w] = max(dp[i] + v,dp[i+w]);
                }
        }
        ll ans = 0;
        for(int i = W; i >= 0 ;i--)if(dp[i] != inf){
                ans = max(ans,dp[i]);
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
