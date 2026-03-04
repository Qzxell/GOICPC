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

int n;int m;
const int mod = 1e9 + 7;
const int N = 1e5  +2;
int v[N];

void so(int test){
    cin >> n >> m;
    f(i,1,n+1)cin >> v[i];
    int dp[n+2][m+2];
    memset(dp, 0 ,sizeof(dp));
    for(int j = 1; j <= n ; j ++){
        for(int i = 1; i <= m ; i ++){
            if(v[j] != 0 and v[j] != i){
                dp[j][i] = 0;
                continue;
            }
            if ( j == 1 ){
                dp[j][i] = 1;
                continue;
            }
            ll owo = 0;
            f(k,max(1,i-1),min(m,i+1)+1){
                owo = (owo + dp[j-1][k])%mod;
            }
            dp[j][i] = owo;
        }
    }
    int ans = 0;
    if(v[n] == 0){
        for(int i = 1 ; i <= m ; i++){
            ans = (ans + dp[n][i])%mod;
        }
    }else{
        ans = dp[n][v[n]];
    }
    //f(i,1,n+1){
        //f(j,1,m+1){
            //cout << dp[i][j] << ' ';
        //}
        //cout << ln;
    //}
    cout << ans ;
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
