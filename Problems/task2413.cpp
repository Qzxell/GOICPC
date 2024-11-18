#include <bits/stdc++.h>

using namespace std;

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define ln '\n'
#define ll long long
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second
#define f(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
#define fer(i, b, a) for(ll i = (ll)a - 1; i >= (ll)b; i--)

const int n = 1e6 + 1;
const int mod = 1e9 + 7;
int dp[n][7];

void init(){

    for(int i = 1; i <= n ; i++){
        for(int j = 1 ; j <= 6 ; j++){
            if (i == 1 and (j==2 or j == 3)) {
                dp[i][j] = 1;
            }
            if (j == 2 or j == 6) {
                dp[i+1][2] = (dp[i+1][2] + dp[i][j])%mod;
                dp[i+1][3] = (dp[i+1][3] + dp[i][j])%mod;
                dp[i+1][6] = (dp[i+1][6] + dp[i][j])%mod;
            }else{
                dp[i+1][1] = (dp[i+1][1] + dp[i][j])%mod;
                dp[i+1][2] = (dp[i+1][2] + dp[i][j])%mod;
                dp[i+1][3] = (dp[i+1][3] + dp[i][j])%mod;
                dp[i+1][4] = (dp[i+1][4] + dp[i][j])%mod;
                dp[i+1][5] = (dp[i+1][5] + dp[i][j])%mod;
            }
        }
    }

}
void so( int test){
    int w;
    cin >> w;
    int ans = 0;
    for(int i = 1; i <= 6 ; i++){
        ans = (ans + dp[w][i])%mod;
    }
    cout << ans << ln;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    init();
    cin >> tt;
    int test = 1;
    while (tt--){
        so(test++);
    }
    return 0;
}
