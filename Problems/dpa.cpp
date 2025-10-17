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
        const int mod = 1e9 + 7;
        int n;
        cin >> n;
        vector<vi> dp(n+2,vi(4,0));
        dp[1][0] = 1;
        dp[1][3] = 1;
        f(i,2,n+1){
                f(color,0,4){
                        if(color == 0){
                                dp[i][color] = (dp[i][color] + 0ll+ dp[i-1][2])%mod;
                                dp[i][color] = (dp[i][color] + 0ll+ dp[i-1][3])%mod;
                        }
                        if(color == 1){
                                dp[i][color] = (dp[i][color] + 0ll+ dp[i-1][0])%mod;
                        }
                        if(color == 2){
                                dp[i][color] = (dp[i][color] + 0ll+ dp[i-1][3])%mod;
                        }
                        if(color == 3){
                                dp[i][color] = (dp[i][color] + 0ll+ dp[i-1][0])%mod;
                                dp[i][color] = (dp[i][color] + 0ll+ dp[i-1][1])%mod;
                        }
                }
        }
        cout <<(0ll+ dp[n][0] + dp[n][3])%mod << ln;
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


