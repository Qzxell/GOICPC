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
    for(int i =1 ; i<=n ; i++){
        cin>> v[i];
    }
    vi dp(n+1,1);

    for(int i =1 ; i<= n ; i++){
        for(int j = i + i ; j<=n ; j+=i){
            if(v[i] < v[j]) dp[j] = max(dp[j],dp[i]+1);
        } 
    }
    int ans = 0;
    for(int i =0 ; i<=n ; i++)ans = max(ans,dp[i]);
    cout << ans << ln;

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
