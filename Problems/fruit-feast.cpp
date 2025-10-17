#include <bits/stdc++.h>
#include <fstream>

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

int main() {
        if (fopen("feast.in", "r")) {
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
}

        int t,a,b;
        cin >> t >> a >> b;
        vector<vi> dp(2,vi(t+1,0));
        dp[0][0] = 1;
        dp[1][0] = 1;
        f(i,0,t+1){
                if(i+a <= t)dp[0][i+a] |= dp[0][i];
                if(i+b <= t)dp[0][i+b] |= dp[0][i];
                dp[1][i/2] |= dp[0][i];
        }
        f(i,0,t+1){
                if(i+a <= t)dp[1][i+a] |= dp[1][i];
                if(i+b <= t)dp[1][i+b] |= dp[1][i];
        }
        int ans = -1;
        f(i,0,t+1)if(dp[1][i] or dp[0][i])ans = i;
        cout << ans << ln;
        return 0;
}



