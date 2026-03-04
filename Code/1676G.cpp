#include<bits/stdc++.h>
#define ln '\n'
#define pb push_back
#define ii pair<int,int> 
#define vii vector<ii>  
#define vi vector<int>  
#define fi first
#define se second
using namespace std;

ii f(int node, int &ans , vector<vi> &tre, vector<bool> &vis, string &s ,vii &dp ){
    ii bk = {0,0};
    vis[node] = 1;
    if (s[node-1] =='B') {
        bk.fi += 1; 
    }else bk.se += 1;

    for(int son : tre[node]){
        if (!tre[node].empty() and vis[son]) {
            continue; 
        }
        ii cur ;
        if (dp[son].fi != -1 and dp[son].se != -1) {
            cur =  dp[son]; 
        }else cur = f(son, ans, tre, vis,s,dp);

        bk.fi += cur.fi;
        bk.se += cur.se;
    }
    if (bk.fi == bk.se) {
        ans++; 
    }
    return bk;
}

void so(){
    int n;
    cin >> n;
    vi v(n);
    vector<vi> tre(n+1);
    vii dp(n+1,{-1,-1});
    for (int i = 1; i < n; ++i) {
        cin >> v[i] ;
    }
    string s;
    cin >> s;
    for (int i = 2; i <= n; ++i) {
        tre[v[i-1]].pb(i);
        tre[i].pb(v[i-1]);
    }
    stack<int> ss;
    vector<bool> vis(n+1,0);
    int ans = 0;
    ii uno =f(1,ans, tre , vis, s, dp);
    cout << ans << ln;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--){
        so();
    }
    return 0;
}

