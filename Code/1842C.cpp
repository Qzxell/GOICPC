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
    int n;
    cin >> n;
    vi v(n+1);
    f(i,1,n+1) cin >> v[i];
    int ma = 1e9 + 2;
    vi memo(n+1,ma);
    vi dp(n+1,ma);
    memo[0] = 0;
    dp[0]= 0;
    for(int i = 1; i <= n ; i ++){
        dp[i] = min(dp[i-1] + 1, memo[v[i]]);
        memo[v[i]] = min(memo[v[i]] , dp[i-1]);
    }
    cout << n - dp[n] << ln;


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
