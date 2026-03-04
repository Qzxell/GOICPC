#include<bits/stdc++.h>

using namespace std;

using ll = long long;

#define forn(i,n) for(int i=0 ;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

void so(int test){
        int n;
        cin >> n;
        vector<int> dp(n,0),p(n),deg(n,0),dis(n,0),reach(n),vis(n,0);
        vector<vector<int>> G(n);
        vector<vector<int>> niv(n+1);
        forn(i,n-1){
                int u,v;
                cin >> u >> v;
                u--;v--;
                deg[u]++;
                deg[v]++;
                G[u].push_back(v);
                G[v].push_back(u);
        }
        auto dfs = [&](auto&& self, int nod,int pat)->int{
                p[nod] = pat;
                int ret = 1;
                reach[nod] = dis[nod];
                for(auto x : G[nod])if(x != pat){
                        dis[x] = dis[nod] + 1;
                        ret += self(self,x,nod);
                        reach[nod] = max(reach[nod],reach[x]);
                }
                return dp[nod] = ret;
        };
        dis[0] = 0;
        dfs(dfs,0,-1);
        forn(i,n)
                niv[dis[i]].push_back(i);

        int ans = (1<<30);
        int baj = 0;
        forn(i,n+1){
                int res = 0;
                for(auto x : niv[i])
                        res += dp[x] - 1;
                ans = min(ans,res + baj);
                for(auto x : niv[i]){
                        if(deg[x] == 1){
                                int u = x;
                                while(reach[u] <= i){
                                        if(vis[u])break;
                                        baj++;
                                        vis[u] = 1;
                                        u = p[u];
                                        if(u == 0)break;
                                }
                        }
                }
        }
        cout << ans << '\n';
}

int main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        int tt = 1;
        cin >> tt;
        int test = 1;
        while(tt--) so(test++);
        return 0;
}


