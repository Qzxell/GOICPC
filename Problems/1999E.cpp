#include<bits/stdc++.h>
#define ln '\n'
#define ll long long 
#define pb push_back
#define vii vector<pair<int,int>>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

const int ga = 2e5 + 2;
int dp[ga];
ll ps[ga];
void so(){
    int l,r;
    cin >> l >> r;
    ll ans = 2*1ll*dp[l];
    ans += ps[r+1] - ps[l+1];
    cout << ans << ln;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    ps[0] = 0;
    for (int i = 3; i < 2e5 + 1; i+=3) {
        dp[i] = dp[i+1] = dp[i+2] = dp[i/3] + 1;
    }
    for (int i = 1; i < 2e5 + 2; i++) {
        ps[i] = ps[i-1] + (1ll)*dp[i-1]; 
    }
    int tt;
    cin >> tt;
    while(tt--){
        so();
    }
    return 0;
}

