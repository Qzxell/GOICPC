#include<bits/stdc++.h>

using namespace std;

#define ll long long 

const int N = 2e5 + 5;
vector<int> G[N];
bool vis[N];
int dp[N];
int p[N];

int dfs(int nod){
        vis[nod] = 1;
        int ret = 1;
        for(auto x : G[nod]){
                if(vis[x])continue;
                p[x] = nod;
                ret += dfs(x);
        }
        return dp[nod] = ret;
}

void so(){
        int n,k,u,v;
        cin >> n >> k;
        for(int i = 0 ; i < n-1 ; i++){
                cin >> u >> v;
                G[u].push_back(v);
                G[v].push_back(u);
        }
        p[1] = -1;
        dfs(1);
        ll ans = 0;
        for(int i = 1 ; i <= n ; i++){
                vector<int> son;
                int ind = -1;
                for(auto x : G[i]){
                        if(x == p[i])continue;
                        son.push_back(dp[x]);
                }
                if(i != 1){
                        son.push_back(n - dp[i]);
                }
                if(n >= k)ans++;
                for(auto x : son){
                        if(n - x >= k)ans += x;
                }
        }
        cout << ans << '\n';
        for(int i = 1 ; i <= n; i++){
                dp[i] = 0;
                vis[i] = 0;
                G[i].clear();
        }
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt;
        cin >> tt;
        while(tt--)so();
        return 0;
}
