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


void so(int test){
    int n,x;
    cin >> n >> x;
    int pr[n+1];
    int pg[n+1];

    vector<vi> dp(n+1,vi (x+1,0));

    f(i,1,n+1)cin >> pr[i];
    f(i,1,n+1)cin >> pg[i];


    f(i,1,n+1){
        f(j,0,x+1){
            
            dp[i][j] = dp[i-1][j];

            if(j >= pr[i] ) {
                dp[i][j] = max(dp[i][j] , dp[i-1][j-pr[i]] + pg[i]);
            }
        }
    }
   //f(i,1,n+1){
        //f(j,0,x+1){
            //cout << dp[i][j] << ' ';
        //}
        //cout << ln;
    //}

    cout << dp[n][x];

}

int main() {

    int tt = 1;
    int test = 1;
    while (tt--){
        so(test++);
    }
    return 0;
}
