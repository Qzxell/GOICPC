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
        ll dp[n+1][k+1];

        vi v(n+1,0);
        f(i,1,n+1)cin >> v[i];

        f(i,0,n+1)f(j,0,k+1)dp[i][j] = 0;

        f(i,1,n+1){
                dp[i][0] = dp[i-1][0] + v[i];
        }

        f(i,1,n+1){
                f(j,0,k+1){
                        ll mi = dp[i-1][j] + v[i];
                        ll mi_e = v[i];
                        for(int l = 1; l <= j; l++){
                                if(i - l < 1)break;
                                mi_e = min(mi_e,1ll*v[i-l]);
                                mi = min(mi,dp[i-l-1][j-l] + mi_e * (i-(i-l)+1));
                        }
                        dp[i][j] = mi;
                }
        }
        //f(i,0,n+1){
                //f(j,0,k+1){
                       //cout <<  dp[i][j] << ' ';
                //}
                //cout << ln;
        //}
        cout << dp[n][k] << ln;
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
